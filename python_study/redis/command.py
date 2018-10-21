#!/bin/env python3
#microserver

import redis, time
from cmd import Cmd
from fabric import Connection
from threading import Thread, Event



class ResponseChannel(Thread):
    def __init__(self, name='response-thread'):
        """ constructor, setting initial variables """
        self._stopevent = Event( )
        self._sleepperiod = 0.1
        Thread.__init__(self, name=name)
        r = redis.StrictRedis(host='halifax', port=6379, db=0)
        self.sub = r.pubsub()
        self.sub.subscribe('response-channel')
        
    def run(self):

        while not self._stopevent.isSet( ):
            message = self.sub.get_message()
            if message:
                # do something with the message
                print(message)
            time.sleep(0.001)  # be nice to the system :)

            
            self._stopevent.wait(self._sleepperiod)
        
    def join(self, timeout=None):
        """ Stop the thread and wait for it to end. """
        self._stopevent.set( )
        Thread.join(self, timeout)
        
        
# if __name__ == "__main__":
    # testthread = TestThread( )
    # testthread.start( )
    # import time
    # time.sleep(5.0)
    # testthread.join( )

        
class Talk(Cmd):
    def __init__(self):
        super().__init__()
        
        self.resp = ResponseChannel('response-channel')
        self.resp.start()
        
        #r = redis.StrictRedis(host='halifax', port=6379, db=0)
        #p = r.pubsub()
        #self.sub = subscribe('response-channel')
        #
        self.req = redis.StrictRedis(host='halifax', port=6379, db=0)
        self.remotes = {}
        
    def _send(self,  message='', remotename='all'):
        self.req.publish('request-channel', "%s:%s" % (remotename,message))
        
        
    def do_exit(self,s):
        self._send('mother is leaving')
        self.resp.join()
        return True
    
    def do_start_remote(self, connstrs):
        self.lastcmd = ''
        connstrs = connstrs.split(' ')
        
        for constr in connstrs:
            self.remotes[constr] = {'conn' : Connection(constr)}
            #Conection(constr)
            
    def do_spawn(self, hosts):
        self._send()
            
    def do_send(self, message):
        self.req.publish('request-channel',message) 
        
        
    def do_test_send(self, message):
        remotename = 'halifax'
        print('channel', 'request-channel-%s' %remotename )
        print('message', "%s" % (message))
        self.req.publish('request-channel-%s' %remotename, "%s" % (message))
            
if __name__ == "__main__":
    cmd = Talk()
    cmd.cmdloop()