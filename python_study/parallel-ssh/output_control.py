#!/bin/sh 
""":" 
exec ${HOME}/.one/bin/python $0 $@  
":"""
from pprint import pprint
from pssh.clients.native import ParallelSSHClient
from gevent import joinall
from pssh.exceptions import Timeout
from time import sleep
import redis

from argparse import ArgumentParser


def get_options():
    parser = ArgumentParser(description='CMD Option Demo.', epilog="best practice opt parser by pete312")
    parser.version = str(1)
    parser.add_argument('--version', action='version', help='print the version and exit')    
    parser.add_argument('--test', '-t', action='store_true', default=False, help='run test()')
  
    return parser.parse_args()
    

config = {
    'CMD_BROKER' : 'halifax'
}
hosts = [
'atlas',
'apollo',
'jupiter'
]

class ResponseChannel:
    def __init__(self, vassal_id, register_actions=[]):
        self.gate = redis.StrictRedis(host=config['CMD_BROKER'], port=6379, db=0)
        self.registered_actions = register_actions
        
        self.vassal_id = vassal_id
    
    def process(self, request, reply_channel=None):

        action = request['data']
        msg = None
        print(action)
        if action in REG_ACTIONS:
            if action == 'restart':
                restart()
            if action == 'protocol':
                msg = {'action' : REG_ACTIONS, 'version' : __version__ }
            if action == 'ping':
                msg = 'pong'
        else:
            msg = "I don't know how to do that mother %s" % hostname
         
        response = self._tran_out(msg)

        self.gate.publish('response-channel', response)
    
    def _tran_out(self,msg):
        return json.dumps(
            dict( 
               vassal_id = self.vassal_id,
               msg = msg
            )
            
        )
        
        
def run(client, cmd, quiet=True, use_pty=True, timeout=1):
    output = client.run_command(cmd, use_pty=use_pty, timeout=timeout)
    if not quiet:
        for o in output:
            print(o)
            
        #print(list(o.stdout))
    # for host in output:
        # for line in output[host].stdout:
            # print( host, line )
    # return client
    return output
    
def run2(client, cmd):
    output = client.run_command(cmd, use_pty=True, timeout=1)
    return output

def send(client, source, dest):
    #client = ParallelSSHClient(hosts)
    greenlets = client.copy_file(source, dest)
    joinall(greenlets, raise_error=True)
    
   
def update(client):
    send(client, './outland.py', '/tmp/outland.py')
    run(client,  'chmod 755 /tmp/outland.py')
    return run2(client, '/tmp/outland.py', use_pty=True, timeout=1)

    
def test(client):
    output = run2(client, '/tmp/outland.py')
    print(output)
    for host in hosts:
        stdout = ''
        try :
            stdout = list(output[host].stdout)
        except Timeout:
            client.reset_output_generators(output[host])
        print( host, r.get(host) )
        print( host, stdout )

if __name__ == "__main__":
    args = get_options()
    client = ParallelSSHClient(hosts)
    r = redis.StrictRedis(host=config['CMD_BROKER'], port=6379, db=0)
    
    if args.test:
        test(client)
        exit()
        
    output = update(client)
    while True:
        for host in hosts:
            stdout = ''
            try :
                stdout = list(output[host].stdout)
            except Timeout:
                client.reset_output_generators(output[host])
            print( host, r.get(host) )
            print( host, stdout )
        sleep(.5)


    exit(1)
        
def out():
    #client = run(hosts, '~/.one/bin/pip install pip --upgrade') 
    #client = run(hosts, '~/.one/bin/pip install redis') 
    #client = run(hosts, '~/.one/bin/pip install invoke') 

    print(type(output['atlas']), client=client )



    for host, host_out in output.items():
        #stdout = list(host_out.stdout)
        try :
            stdout = list(host_out.stdout)
        except Timeout:
            client.reset_output_generators(host_out)
    exit()

    while True:
      for o in output:
        #print(type(output[o]) )
        #print( dir(output[o]) )
        print(output[o].get(1))
        print(list(output[o].stdout))
        #for line in host_output.stdout:
        #    print(host, line)
        sleep(.2)