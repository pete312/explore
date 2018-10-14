#!/bin/env python3

from colored import fg, attr

print('take a look at gucharmap')
print('and https://www.pythonsheets.com/notes/python-unicode.html')

print("interesting range of characters")
#for c in range(int(0xff), int(0xd700)): 
#    print("%X %s" % (c, chr(c)))


def cprint(start, finish, i=[1]):
    print("\n\n---range(%x - %x)------------------------------------------------\n" % (start,finish))
    for c in range(int(start), int(finish)):
        print('%s %s' % (fg(i[0]), chr(c)),end='')
        i[0] = i[0] % 200 + 1
    print(attr(0))

i = 1
cprint(0x2500,0x2900,[i])
cprint(0x2ff0,0x2ffe,[i])
cprint(0x2d80,0x2e00,[i])
cprint(0x2500,0x26b5,[i])
cprint(0x2d30,0x2d66,[i])

# ⴰⴱⴲⴳⴴⴵⴶⴷⴸⴹⴺⴻⴼⴽⴾⴿⵀⵁⵂⵃⵄⵅⵆⵇⵈⵉⵊⵋⵌⵍⵎⵏⵐⵑⵒⵓⵔⵕⵖⵗⵘⵙⵚⵛⵜⵝⵞⵟⵠⵡⵢⵣⵤⵥ>>>
