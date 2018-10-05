from fabric import task

@task
def hello(c):
    '''echo a hello on the remote machine'''
    f =  c.run("echo hello from `hostname`")
    print("the return object from the run command")
    for i in dir(f):
        print(" . %20s :  %s" % ( i, getattr(f,i, None)))

    
@task
def list(c):
    '''demo of listing out the hosts file'''
    with c.cd('/etc'):
        c.run('ls -l hosts')
        c.get('hosts', 'myhosts')
    with c.lcd('/etc'):
        c.local('ls -l /etc/hosts')
        
        
@task
def sudo(c):
    '''demo of using the fabric\'s sudo command'''
    c.sudo("tail /var/log/messages")