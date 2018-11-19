#!/bin/bash
""":" 
exec ${HOME}/.one/bin/python $0 $@ 
"""
import redis
from time import sleep

r = redis.StrictRedis(host='localhost', port=6379, db=0)

state = {}

while 1:
    for host in ['apollo', 'jupiter', 'atlas']:
        state[host] =  r.get(host)
        print(host, state[host])
    print ("----")
    sleep(1)