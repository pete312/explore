#!/bin/env python2

# Pete Moore May 5 2018
# best practice use of python's generic logger module

import logging, logging.handlers
import sys, os
from argparse import ArgumentParser

# get the script's filename less the path and the .py extension if it has one.
prog_name = os.path.basename(__file__).rsplit('.py', 1)[0] 

print "\nstarting %s as logger name %s " %( sys.argv[0], prog_name )


logger = logging.getLogger(prog_name)


def get_options(): 
    _LOGLEVELS = ('CRITIAL','ERROR','WARNING','WARN','INFO','DEBUG')
    parser = ArgumentParser(description='Logger Demo.', epilog="best practice logger by pete moore")
    parser.add_argument('--loglevel', '--verbosity', '-v', choices=_LOGLEVELS,  default='INFO', help='set the log level')
    parser.add_argument('--stdout', '-s', type=bool, default=False, help='set the log level')
    return parser.parse_args()

def setup_logger(logger, path_name=None, level="DEBUG", stdout=False):
    formatter = logging.Formatter("%(asctime)s %(name)s %(levelname)s : %(message)s")
    logger.setLevel(logging.getLevelName(level))
    
    if path_name:
        loghandler = logging.handlers.RotatingFileHandler( path_name, maxBytes=300000, backupCount=5)
        loghandler.setFormatter(formatter)
        logger.addHandler(loghandler)
    
    if stdout:
        loghandler = logging.StreamHandler(sys.stdout)
        loghandler.setFormatter(formatter)
        logger.addHandler(loghandler)
        
    if stdout is False and path_name is None:
        loghandler = logging.NullHandler()
        logger.addHandler(loghandler)
        
    return logger


if __name__ == "__main__":
    args = get_options()
    
    # decorate the logger with our settings.
    setup_logger(logger, level=args.loglevel, stdout=args.stdout)
    print args
    
    logger.info("test")
    print "done\n"