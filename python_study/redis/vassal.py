#!/bin/env python

import sys, time, os
from time import sleep
from threading import Thread, Event
import socket
import json

hostname = socket.gethostname()
vassel_id = hostname
REG_ACTIONS = ['restart']

config = {
    'VE_BIN' = '/tmp/vv2/bin' 
}

class RequestChannel(Thread):
    def __init__(self, queue, name='request-thread'):
        """ constructor, setting initial variables """
        self._stopevent = Event( )
        self._sleepperiod = 0.1
        self.queue = queue
        Thread.__init__(self, name=name)
        r = redis.StrictRedis(host='halifax', port=6379, db=0)
        self.sub = r.pubsub()
        self.sub.subscribe('request-channel')
        self.sub.subscribe('request-channel-%s' % vassel_id)
        
      
        
    def run(self):

        while not self._stopevent.isSet():
            message = self.sub.get_message()
            if message:
                # do something with the message
                if message['type'] == 'subscribe':
                    print('subscribed to %s' % message['channel'])
                    continue
                print(message)
                
                self.queue.put(message)
                
            time.sleep(0.001)  # be nice to the system :)

            
            self._stopevent.wait(self._sleepperiod)
        
    def join(self, timeout=None):
        """ Stop the thread and wait for it to end. """
        self._stopevent.set( )
        Thread.join(self, timeout)
        
       

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
        os.execve( __file__, sys.argv[0:])
    else:
        print('bootstrap')
        bootstrap()
        

def run_action(action):
    print(action)
    

def isa_virtualenv():
    print(sys.path[1])
    return not sys.path[1].startswith('/usr')
    
def spawn(hosts):
    for host in hosts:
        c = fabric.Connect(host)
        c.run("hostname")
        
def process(stuff, reply_channel=None):

    action = stuff['data']
    msg = None
    if action in REG_ACTIONS:
        if action == 'restart':
            restart()
    else:
        msg = "I %s don't know how to do that mother" % hostname
        print()
        
    response = json.dumps(
        dict( 
           host = hostname,
           msg = msg
        )
        
    )
    if getattr(process, 'reply_channel', None):
        process.reply_channel.publish('response-channel', response)
    else:
        process.reply_channel = redis.StrictRedis(host='halifax', port=6379, db=0)
        process.reply_channel.publish('response-channel', response)
        
    
def mainloop():
    q = Queue()
    req = RequestChannel(q)
    req.start()

    while True:
        try:
            stuff = q.get(timeout=.4)
            print("in::", stuff)
            try:
                data = json.loads(stuff)
            except TypeError:
                print('unable parse')
                continue
            process(stuff)
        except Empty:
            pass
        
    req.join()

    
if __name__ == '__main__':
    
    print(sys.path[1])
    if isa_virtualenv():
        import redis, fabric
        from queue import Queue, Empty
        mainloop()
    else:
        print("bootstraping")
        bootstrap()