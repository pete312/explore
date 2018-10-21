#!/bin/env python

import redis, time


#microserver


r = redis.StrictRedis(host='localhost', port=6379, db=0)
p = r.pubsub()
p.subscribe('my-first-channel', 'my-second-channel', ...)
p.psubscribe('my-*')

while True:
    message = p.get_message()
    if message:
        # do something with the message
        print(message)
        time.sleep(0.001)  # be nice to the system :)