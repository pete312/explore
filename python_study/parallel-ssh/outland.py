#!/bin/bash
""":" 
exec ${HOME}/.one/bin/python $0 $@ 
"""
import redis
import invoke
import socket
from time import sleep
import os

config = {
    'CMD_BROKER' : 'halifax'
}

print(os.getpid())
r = redis.StrictRedis(host=config['CMD_BROKER'], port=6379, db=0)

for i in range(3):

    r.set( socket.gethostname(), str(i) )
    #print (i)
    sleep(1)


