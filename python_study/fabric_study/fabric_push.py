#!/bin/env python3

from socket import gethostname
from getpass import getpass
from argparse import ArgumentParser
from fabric import Connection, Config
import fabric
import bottle
import threading

VERSION = '0.1'

def get_options():
    parser = ArgumentParser(description='fabric test v{}'.format(VERSION), epilog="...")
    parser.version = str(VERSION)
    parser.add_argument('--version', action='version', help='print the version and exit')
    parser.add_argument('-c', '--count', type=int, default=1, help='numebr of times operation happens remotely')
    parser.add_argument('-x', '--noof_conn_per_host', type=int, default=1, help='numebr of times operation happens remotely')
    parser.add_argument('-P', '--setpass', dest='password', default=False, help='set user password')
    parser.add_argument('-p', '--askpass', dest='password', action='store_true', default=False, help='ask for password prompt')
    parser.add_argument('-H', '--hosts', metavar='N', type=str, nargs='+',
                        help='hosts to act on (user is current user unless notation user@host is used)')
    
   
    
    return parser.parse_args()

def make_metrics(c):
    c.run('data')
    
    with open('/tmp/test','w') as f:
        f.write(data)
        
def run_remote(c):
    c.run('hostname')
    
    

def pool_connections(hosts, password=None, ncph=1):
    '''
      pool_connections(host, password=None, ncph=1)
        Returns a hash of connection objects to the host list provided
        hosts    - list of hosts to connect to. Fabric supports user@host:port connection syntax
        password - Try password but False values (Flase, None or '' etc) will use certificate authentication. 
        ncph     - Number of connections per host will open multiple ssh connections for performance measurements.
    '''

    connection_pool = {}
    for host in hosts:
        for c in range(ncph):
            hosthash = "%s-%d" % (host, c + 1)
            print(hosthash)
            if password:
                connection_pool.update({ hosthash  : Connection(host, connect_kwargs={'password': password})} )
            else:
                connection_pool.update({ hosthash  : Connection(host)} )
        
    return connection_pool
    
def zip_manifest(manifest):
    pass
    
def use_proxy_server(port):
    pass
    
        
if __name__ == '__main__':
    args = get_options()
    if args.password:
        print("pass",  args.password)
        if args.password == True:
            args.password = getpass("user password: ")

    connection_pool = pool_connections(args.hosts, password=args.password, ncph=args.noof_conn_per_host)
    
    for i in range(args.count):
        for host, c in connection_pool.items():
            #run_remote(ctx)
            print (host)
            c.run("echo =--------user `whoami`")
            c.put("test" , '/tmp/test')
            #c.run("time cat /etc/hosts")
        
        
        