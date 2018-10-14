#!/bin/env python3


import colored

print('https://pypi.org/project/colored/')

for i in range(1,255):  
    print('%s color test %s' %  ( colored.fg(i), colored.attr(0) ))
    
input("enter to continue")

for i in range(1,255):  
    print('%s color test %s' %  ( colored.fg(i), colored.attr(0) ))
    for ii in range(1,255):
        print('%s%s color test %s' %  ( colored.fg(i), colored.bg(ii), colored.attr(0) ))
