#!/bin/env python3
#

VERSION = 0.1
from argparse import ArgumentParser
import xml.etree.ElementTree as ET
from cmd import Cmd
import os, sys


def get_options():
    parser = ArgumentParser(description='xml parse.', epilog="...")
    parser.version = str(VERSION)
    parser.add_argument('--version', action='version', help='print the version and exit')
    parser.add_argument('--file','-f', action='store', type=str, required=True, help="xml file")
    return parser.parse_args()
    
    

            
class Interact(Cmd):
    def __init__(self, xmlfile):
        Cmd.__init__(self)
        tree = ET.parse(xmlfile)
        print('loading xml', xmlfile)
        self.root = tree.getroot()
        self.sample = open(xmlfile).read()
        self.file = xmlfile
        self.cursor = self.root
        
    def do_showroot(self, cmd):
        '''shows the root node tag and attributes to that node'''
        print("{:.<20}".format( "root " ), self.root)
        print("{:.<20}".format( "root.tag "), self.root.tag)
        print("{:.<20}".format( "root.attrib " ), self.root.attrib)
        
    def do_showrootnodes(self, cmd):
        for child in self.root:
            print("root {:.<10} tag {:.<20} attrs {}".format(self.root.tag, 
                                                             child.tag, 
                                                             child.attrib))
            
    def do_find(self, cmd):
        
        for child in self.root:
            #if cmd in str(child.attrib.values()).split(','):
            print([ txt.split(',') for txt in child.attrib.values()])
            if cmd in [ txt.split(',') for txt in child.attrib.values()]:
                print("root {:.<10} tag {:.<20} attrs {}".format(self.root.tag, 
                                                             child.tag, 
                                                             child.attrib))
            
    def do_findgroups(self, group):
        for child in self.root:
            if 'groups' not in child.attrib:
                print('data dosnt have an groups attribute')
                return
                
            if group in child.attrib['groups'].split(','):
                    print("root {:.<10} tag {:.<20} attrs {}".format(self.root.tag, 
                                                             child.tag, 
                                                             child.attrib))
                                                             
    def do_findid(self, id):
        for child in self.root:
            if 'groups' not in child.attrib:
                print('data dosnt have an id attribute')
                return 
                
            if id in child.attrib['id'].split(','):
                print("root {:.<10} tag {:.<20} attrs {}".format(self.root.tag, 
                                                             child.tag, 
                                                             child.attrib))
    def do_showsample(self,cmd):
        '''shows the sample data'''
        print("\nfrom file", self.file, "\n")
        print("-----\n" + self.sample +"\n-----")
        
    def do_loadsample(self, xmlfile):
        tree = ET.parse(xmlfile)
        self.root = tree.getroot()
            
    def do_reload(self, s):
        '''restart this menu'''
        os.execv( __file__, sys.argv[0:] )
        
       
    def do_exit(self, s):
        return True
        
    def do_quit(self, s):
        return True
        
        
if __name__ == "__main__":

    args = get_options()
    
    cli = Interact(args.file)
    cli.cmdloop()
    
    