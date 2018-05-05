#!/bin/env python2

# bottle demo 2
# Peter Moore Apr 2013

import bottle 
import os.path
import socket


usage = ''' <html>
<body>
<h2> bottle_filereader.py: Demo to show how to use bottle to serve up file content </h2>

Usage:
<ul>
<li>http://{{hostname}}:8090/exists/&lt;filepath&gt;<ul><li> test if a file name on {{ hostname }} exists </li></ul></li>
<li>http://{{hostname}}:8090/get/&lt;filepath&gt;<ul><li> Display the contents of a file on {{hostname}} </li></ul></li>
<li>Example <a href="./exists/etc/hosts" > test the existance of /etc/hosts </a> </li>
<li>Example <a href="./get/etc/hosts" > Show contents of /etc/hosts </a></li>
</ul>
</body><html>
'''

dir_contents = """
<html><body>
    <ui>
        % for item in stuff:
           {{ item }}
        % end
    </ui>
</body></html>
"""

@bottle.route("/")
def index():
    return bottle.template(usage, hostname = socket.gethostname())

@bottle.route("/get/<filepath:path>")
def get(filepath):
    filepath = "/" + filepath
    print "getting", filepath 
    if not os.path.exists(filepath):
        return "file not found"
        
    if os.path.isdir(filepath):
        content = "><h1>dir contents of %s :</h1>" % filepath
        stuff = []
        os.path.walk(filepath, visitor , stuff )
     
        
        print bottle.template(dir_contents, stuff = stuff )
        return "DONE"
    
    try:
        #print open(filepath).read() # prints file 
        content = '<br>\n'.join(open(filepath).read().split("\n")) # prints file with <br> 
        return "<plaintext>" + content
        
    except Exception as e:
        return "<h1>request threw an error ;</h1><br>"  + str(e) 


@bottle.route("/exists/<filepath:path>")
def exists(filepath):
    filepath = "/" + filepath
    return str(os.path.exists(filepath))
    

def visitor(container, dir, names):
    container.append("<ul>" + dir + "\n")
    if names == None:
        print "NONE??"
        return
    for name in names:
        
        container.append("<li>" + name + "</li>\n")

    container.append("</ul>\n")
    
bottle.run(host='0.0.0.0', port=8090, reloader=True)