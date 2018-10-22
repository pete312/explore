#!/bin/env python

# a bootstrapping vassal to command
# Author : Pete Moore 


import sys, time, os
from time import sleep
from threading import Thread, Event
import socket
import json

__version__ = '0.0.1'
hostname = socket.gethostname()
vassal_id = hostname
REG_ACTIONS = ['restart','ls','pwd','protocol']

config = {
    'VE_BIN': '/tmp/vv2/bin',
    'CMD_BROKER' : 'halifax'
}

class RequestChannel(Thread):
    def __init__(self, vassal_id, queue, name='request-thread'):
        """ constructor, setting initial variables """
        self._stopevent = Event( )
        self._sleepperiod = 0.1
        self.gate = queue
        Thread.__init__(self, name=name)
        r = redis.StrictRedis(host=config['CMD_BROKER'], port=6379, db=0)
        self.sub = r.pubsub()
        self.sub.subscribe('request-channel')
        self.sub.subscribe('request-channel-%s' % vassal_id)
        
      
        
    def run(self):

        while not self._stopevent.isSet():
            message = self.sub.get_message()
            if message:
                # do something with the message
                if message['type'] == 'subscribe':
                    print('subscribed to %s' % message['channel'])
                    continue
                print(message)
                
                self.gate.put(message)
                
            time.sleep(0.001)  # be nice to the system :)

            self._stopevent.wait(self._sleepperiod)
        
    def join(self, timeout=None):
        """ Stop the thread and wait for it to end. """
        self._stopevent.set( )
        Thread.join(self, timeout)
        
        
#class ResponseChannel(object):
class ResponseChannel:
    def __init__(self, vassal_id, register_actions=[]):
        self.gate = redis.StrictRedis(host=config['CMD_BROKER'], port=6379, db=0)
        self.registered_actions = register_actions
        
        self.vassal_id = vassal_id
    
    def process(self, request, reply_channel=None):

        action = request['data']
        msg = None
        if action in REG_ACTIONS:
            if action == 'restart':
                restart()
            if action == 'protocol':
                msg = {'action' : REG_ACTIONS, 'version' : __version__ }
        else:
            msg = "I don't know how to do that mother" % hostname
         
        response = self._tran_out(msg)

        self.gate.publish('response-channel', response)
    
    def _tran_out(self,msg):
        return json.dumps(
            dict( 
               vassal_id = self.vassal_id,
               msg = msg
            )
            
        )
        


def bootstrap():
    ''' bootstrap into a ve from standard lib '''
    os.environ['PATH'] = "%s:%s" % (config['VE_BIN'], os.environ['PATH'])
    os.execve( __file__, sys.argv[0:], os.environ)
        

def restart(countdown=0):
    print('restarting')
    for i in range(countdown,0):
        
        print('..', countdown - i)
        sleep(1)

    if isa_virtualenv():
        print('bouncing')
        os.execve( __file__, sys.argv[0:], os.environ)
    else:
        print('bootstrap')
        bootstrap()

def run_action(action):
    print(action)
    
def isa_virtualenv():
    return not sys.path[1].startswith('/usr')
    
def spawn(hosts, resp):
    for host in hosts:
        c = fabric.Connect(host)
        c.run("hostname")
        resp.puslish()
       
    
def mainloop():
    req_q = Queue()
    rchan = RequestChannel(vassal_id, req_q)
    resp = ResponseChannel(vassal_id, REG_ACTIONS)
    
    rchan.start()

    while True:
        try:
            stuff = req_q.get(timeout=.4)
            print(type(stuff), stuff)
            resp.process(stuff)
        except Empty:
            pass
        
    rchan.join()

    
if __name__ == '__main__':
    
    print(sys.path[1])
    if isa_virtualenv():
        import redis, fabric
        # this will break from python 2 to 3
        #from queue import Queue, Empty
        from Queue import Queue, Empty
        mainloop()
    else:
        print("bootstraping")
        bootstrap()