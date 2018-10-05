#!/bin/env python2

# Pete Moore May 5 2018
# best practice use of python's generic logger module

import logging, logging.handlers
import sys, os
from argparse import ArgumentParser

DEFAULT_FORMAT = "%(asctime)s %(name)s %(module)s %(funcName)s line %(lineno)s %(levelname)s : %(message)s"

# get the script's filename less the path and the .py extension if it has one.
prog_name = os.path.basename(__file__).rsplit('.py', 1)[0] 

print "\nstarting %s as logger name %s " %( sys.argv[0], prog_name )

# importing here will not make the module's  

logger = logging.getLogger() # get the root logger
import lib.logger_test_module as loglib


def get_options(): 
    _LOGLEVELS = ('CRITIAL','ERROR','WARNING','WARN','INFO','DEBUG')
    parser = ArgumentParser(description='Logger Demo.', epilog="best practice logger by pete moore")
    parser.add_argument('--loglevel', '--verbosity', '-v', choices=_LOGLEVELS,  default='INFO', help='set the log level')
    parser.add_argument('--logformat', '-f', default=DEFAULT_FORMAT, help='custom log format see  https://docs.python.org/2/library/logging.html#logrecord-attributes')
    
    parser.add_argument('--log', '-l', default=None, help='output logfile (default None)')
    parser.add_argument('--copytoscreen', '-s', action='store_true', default=False, help='copy logs to stdout')
    return parser.parse_args()

def setup_logger(logger, path_name=None, level="DEBUG", stdout=False, format=DEFAULT_FORMAT):
    formatter = logging.Formatter(format)
    logger.setLevel(logging.getLevelName(level))
    
    if path_name:
        print "adding path_name" , path_name
        loghandler = logging.handlers.RotatingFileHandler( path_name, maxBytes=300000, backupCount=5)
        loghandler.setFormatter(formatter)
        logger.addHandler(loghandler)
    
    if stdout:
        loghandler = logging.StreamHandler()
        loghandler.setFormatter(formatter)
        logger.addHandler(loghandler)
        
    if stdout is False and path_name is None:
        loghandler = logging.NullHandler()
        logger.addHandler(loghandler)
        
    return logger


if __name__ == "__main__":
    args = get_options()
    
    # decorate the logger with our arg settings.
    setup_logger(logger, path_name=args.log, level=args.loglevel, stdout=args.copytoscreen, format=args.logformat)
    
    
    print args
    
    logger.info("starting app")
    loglib.funcA("msg point 1")

    print "setting logging to level INFO"
    logger.setLevel(logging.getLevelName('INFO'))
    loglib.funcA("message at INFO level")
        
    print "done\n"