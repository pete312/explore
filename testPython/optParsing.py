#!/bin/env python3
# Pete Moore may 5 2018
# show demo use of Arguments

VERSION = 0.1
from argparse import ArgumentParser


_LOGLEVELS = ('CRITIAL','ERROR','WARNING','INFO','DEBUG')

def get_options():
    parser = ArgumentParser(description='Logger Demo.', epilog="best practice logger by pete312")
    parser.version = str(VERSION)
    parser.add_argument('--version', action='version', help='print the version and exit')
    parser.add_argument('--loglevel', choices=_LOGLEVELS, default='INFO', help='log to stdout')
    
    parser.add_argument('--default-false-bool', '-t', action='store_true', default=False, help='override the usually False flag')
    parser.add_argument('--default-true-bool', '-f',action='store_false', default=True, help='override the usually True flag')
    
    parser.add_argument('--intopt', action='store', type=int, default=1, help='store any int')
    parser.add_argument('--floatopt', action='store', type=float, default=1.0, help='store any float')
    parser.add_argument('--stropt', action='store', type=str, default='foo', help='store any str')
    parser.add_argument('--i-am-required','-r', action='store', type=str, required=True, help="I can't be ignored")
    return parser.parse_args()
    
    
    
if __name__ == "__main__":

    args = get_options()
    
    print()
    print("arg namespace is", args)
    print("the required arg is set to..", args.i_am_required)
    print("loglevel arg is set to ....." + str(args.loglevel))
   
    
    
    