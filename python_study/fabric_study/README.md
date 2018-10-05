Fabric 2.x tests
====

These tests will not probably work in version 1.x fabric.

    pip install fabric
    $ cd <directory where fabfile.py is>
------
# list commands abvailable in the fabfile.py with --list

    usr1@host1 $ fab --list
    Available tasks:
    
      hello   echo a hello on the remote machine
      list    demo of listing out the hosts file
      sudo    demo of using the fabric's sudo command

------
# the list demo will ls -l the hosts file on the remote host

    usr1@host1 $ fab -H host2 list
    -rw-r--r-- 1 root root 131 Nov 28  2017 hosts


------

# hello demo will print the message ' hello from <remote hostname> '
    (p3) usr1@host1 > fab -H host1 hello
    hello from host2
    the return object from the run command
     .             __bool__ :  <bound method Result.__bool__ of <Result cmd='echo hello from `hostname`' exited=0>>
     .            __class__ :  <class 'fabric.runners.Result'>
     .          __delattr__ :  <method-wrapper '__delattr__' of Result object at 0x7f953c39b7f0>
     .             __dict__ :  {'stdout': 'hello from host2\n', 'stderr': '', 'encoding': 'UTF-8', 'command': 'echo hello from `hostname`', 'shell': '/bin/bash', 'env': {}, 'exited': 0, 'pty': False, 'hide': (), 'connection': <Connection host=host2>}
     .              __dir__ :  <built-in method __dir__ of Result object at 0x7f953c39b7f0>
     .              __doc__ :
        An `invoke.runners.Result` exposing which `.Connection` was run against.

        Exposes all attributes from its superclass, then adds a ``.connection``,
        which is simply a reference to the `.Connection` whose method yielded this
        result.

        .. versionadded:: 2.0

     .               __eq__ :  <method-wrapper '__eq__' of Result object at 0x7f953c39b7f0>
     .           __format__ :  <built-in method __format__ of Result object at 0x7f953c39b7f0>
     .               __ge__ :  <method-wrapper '__ge__' of Result object at 0x7f953c39b7f0>
     .     __getattribute__ :  <method-wrapper '__getattribute__' of Result object at 0x7f953c39b7f0>
     .               __gt__ :  <method-wrapper '__gt__' of Result object at 0x7f953c39b7f0>
     .             __hash__ :  <method-wrapper '__hash__' of Result object at 0x7f953c39b7f0>
     .             __init__ :  <bound method Result.__init__ of <Result cmd='echo hello from `hostname`' exited=0>>
     .    __init_subclass__ :  <built-in method __init_subclass__ of type object at 0x555d139d72a8>
     .               __le__ :  <method-wrapper '__le__' of Result object at 0x7f953c39b7f0>
     .               __lt__ :  <method-wrapper '__lt__' of Result object at 0x7f953c39b7f0>
     .           __module__ :  fabric.runners
     .               __ne__ :  <method-wrapper '__ne__' of Result object at 0x7f953c39b7f0>
     .              __new__ :  <built-in method __new__ of type object at 0x7f954b40cf20>
     .          __nonzero__ :  <bound method Result.__nonzero__ of <Result cmd='echo hello from `hostname`' exited=0>>
     .           __reduce__ :  <built-in method __reduce__ of Result object at 0x7f953c39b7f0>
     .        __reduce_ex__ :  <built-in method __reduce_ex__ of Result object at 0x7f953c39b7f0>
     .             __repr__ :  <bound method Result.__repr__ of <Result cmd='echo hello from `hostname`' exited=0>>
     .          __setattr__ :  <method-wrapper '__setattr__' of Result object at 0x7f953c39b7f0>
     .           __sizeof__ :  <built-in method __sizeof__ of Result object at 0x7f953c39b7f0>
     .              __str__ :  <bound method Result.__str__ of <Result cmd='echo hello from `hostname`' exited=0>>
     .     __subclasshook__ :  <built-in method __subclasshook__ of type object at 0x555d139d72a8>
     .          __weakref__ :  None
     .              command :  echo hello from `hostname`
     .           connection :  <Connection host=host2>
     .             encoding :  UTF-8
     .                  env :  {}
     .               exited :  0
     .               failed :  False
     .                 hide :  ()
     .                   ok :  True
     .                  pty :  False
     .          return_code :  0
     .                shell :  /bin/bash
     .               stderr :
     .               stdout :  hello from host2

(p3) usr1@host1 >

------
# sudo will demo the sudo() function listed in the fabfile.py 
# needs the long option of --prompt-for-sudo-password (someone should make a short ver)
    (p3) usr1@host1 > fab --prompt-for-sudo-password -H <hostname> sudo
    Desired 'sudo.password' config value:
    [sudo] password:
    Oct  3 06:26:00 <hostname> liblogging-stdlog:  [origin software="rsyslogd" swVersion="8.24.0" x-pid="256" x-info="http://www.rsyslog.com"] rsyslogd was HUPed
    Oct  3 23:27:22 <hostname> ansible-ping: Invoked with data=pong
    Oct  3 23:27:47 <hostname> ansible-ping: Invoked with data=pong
    Oct  4 06:25:08 <hostname> liblogging-stdlog:  [origin software="rsyslogd" swVersion="8.24.0" x-pid="256" x-info="http://www.rsyslog.com"] rsyslogd was HUPed

-----------

# 