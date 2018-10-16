#!/bin/env python

import redis

r = redis.StrictRedis(host='localhost', port=6379, db=0)
r.publish('my-first-channel', 'some data')