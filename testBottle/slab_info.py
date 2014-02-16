#!/usr/bin/python
# Author pete moore Jun 2012
# small web demo to show stats in /proc dir with the bottle

from bottle import route, run, get, post
from sys import argv, exit
import bottle
import os


exclude = ['exe']

port = 8090

@route('/slab/<name:re:\d\d.+>')
def test(name='World'):
    return '<b>Hello %s!</b>' % name
   
def read_file( file):
	response_obj = ""
	if os.path.isdir(file):
		return  "<p><B> (dir) %s </B><br>" % file
		
	response_obj += "<p><B> %s </B><br>" % file
	f = open(file)
	for line in f.readlines():
		response_obj += line + " <br>"
	f.close()
	return response_obj
   
@route('/proc/<name>')
def slab_info(name):
	response = "SLAB STAT FOR %s<p>"% name 
	if os.path.isdir("/proc/" + name):
		for filename in os.listdir("/proc/" + name):
			if filename in exclude:
				print "im here"
				response += "skipping %s becuase binary" % filename
			else:
				response += read_file( "/proc/" + name + "/" + filename)
		return response
	else:
		response += read_file("/proc/" + name)
		return response
   
   
@route('/')
def index():

	baselink = 'http://localhost:%d' % port		
		
	response = '<b>Bottle Example %s</b>' % argv[0]
	response += "<p>Select what slab stat from the links below"
	
	for object in os.listdir("/proc"):
		response += '<br><a href="%s/proc/%s"> %s </a>'   % (baselink , object, object ) 

	return response
    
@route('/routes')
def show_routes():
    return "" 

def good_platform():
	# if on windows, this will only work under cygwin 
	if os.name == 'nt':
		return False
	else: 
		return True
	
		
	
if not good_platform():
	print "To run this on windows, you must run it from Cygwin python"
	exit(1)

run(host='localhost', port=port)

