#!/bin/env python
#microserver

import redis, time
from cmd import Cmd
#from fabric import Connection
from fabric.api import execute, run, env, hosts, roles, parallel
from threading import Thread, Event
import os, sys



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
        
       
    
def run_parallel(host, *args, **kwargs):
    #if type(hosts) == str:
    env.hosts = [host]
    @parallel
    def do_work(c):
        c.run('ls -l')
    
    execute(do_work, *args, **kwargs)
        
class Talk(Cmd):
    def __init__(self):
        super().__init__()
        self.prompt ='\n(all) ' 
        
        self.resp = ResponseChannel('response-channel')
        self.resp.start()
        
        self.req = redis.StrictRedis(host='halifax', port=6379, db=0)
        self.remotes = {}
        
    def _send(self,  message='', remotename='all'):
        self.req.publish('request-channel', "%s:%s" % (remotename,message))
        
        
    def do_exit(self,s):
        self._send('mother is leaving')
        self.resp.join()
        return True
    
    def do_address(self, ctx):
        self.prompt = "(%s) " % ctx
        
    def do_reload(self, s):
        os.execv( __file__, sys.argv[0:] )
    
    def do_ping(self, conn=''):
        if conn:
            self.sendto(conn, 'ping')
        else:
            self.send('ping')
            
    
    def do_start_remote(self, connstrs):
        self.lastcmd = ''
        
        #run_parallel(connstrs)
        
        #env.hosts = connstrs.split(' ')
        
        @parallel
        def do(*args, **kwargs):
            print('here', args , kwargs)
            a = run('hostname')
            run('sleep 1')
            b = run('ls')
            print(b)
            #c.run('/tmp/vassel.py')
        execute(do, *(1,2,3), hosts=connstrs.split(' '), **{'a': 23})
            
    def do_spawn(self, hosts):
        self._send()
        
    def send(self, message):
        self.req.publish('request-channel', message) 
        
    def sendto(self, conn, message):
        for c in conn.split(' '):
            self.req.publish('request-channel-%s' % c, message) 
            
    def do_send(self, message):
        self.req.publish('request-channel',message) 
        
    def do_test(self, hosts):
        
        execute()
        
    def do_test_send(self, message):
        remotename = 'halifax'
        print('channel', 'request-channel-%s' %remotename )
        print('message', "%s" % (message))
        self.req.publish('request-channel-%s' %remotename, "%s" % (message))
            
if __name__ == "__main__":
    cmd = Talk()
    cmd.cmdloop()