#!/bin/env python3


from inspect import currentframe
from pprint import pformat

RESET = "\x1b[0m"
cl_reset='\033[0m'
fg_lightgrey='\033[37m'
fg_yellow='\033[93m'

def fg(n):
    assert -1 < n < 256, f"{n} value outside (0,255)"
    return f"\x1b[38;5;{n}m"

def bg(n):
    assert -1 < n < 256, f"{n} value outside (0,255)"
    return f"\x1b[48;5;{n}m"
    

def grey(s):
    return fg_lightgrey + str(s) + cl_reset

def yellow(s, alt=None):
    if alt:
        return alt % s 
    return fg_yellow + str(s) + cl_reset
    
    
def peek(d, color=None):
    '''
    peek at a value returning its contents. Will label the output with the line number. 
    
    '''
    last_line = (currentframe().f_back).f_lineno
    _label = f'{last_line:-4d}:'
    if color:
        print(_label, color(str(d)))
    else:
        print(_label, str(d))
    if last_line in peek.bp:
        input(f'bp line {last_line}')
    return d
    
peek.bp = []


def label(c, d, color=str, format=False):
    if c and c[-1] == '\n':
        c = yellow('%s ..\n' % c[:-1] )
    else:
        c = yellow('%s ..' % c )
    last_line = (currentframe().f_back).f_lineno 
    _label = '%-4d: %s' % (last_line, c)
    if isinstance(d, str):
        if format:
            return grey(_label) + " " + color(d)
        else:
            print(grey(_label), color(d))
    else:
        if format:
            return grey(_label) + " " + color(pformat(d))
        else:
            print(grey(_label), color(pformat(d)))
    if last_line in label.bp:
        input(f'bp line {last_line}')
    return d
    
label.bp = []


print("The 1st 16 colors")
for i in range(0,16):
    print(f"{fg(0)}{bg(i)}[{i:03d}]" , end = RESET)

print("\nthe rest\n")
bump = 0
for i in reversed(range(16,227,6)):
    print(' ' * int( bump / 6) , end='')
    for j in range(0,6):
        print(f"{fg(0)}{bg(i + j)}[{i + j:03d}]", end = RESET)
    print()
    bump += 1



def print_color_range(name, clist):
    rangelen = len(clist)
    fore = fg(0) # black pen
    for i in range(rangelen):
        code = clist[i]
        fore = fg(clist[0]) if i >= rangelen / 2 else fg(clist[-1])
        back = bg(clist[i])
        print(f"{fore}{back}[{clist[i]:03d}]",  end = RESET)
    print(name)
    
def print_color_range(name, clist):
    rangelen = len(clist)
    fore = fg(0) # black pen
    for i in range(rangelen):
        code = clist[i]
        back = bg(clist[i])
        print(f"{fore}{back}[{clist[i]:03d}]",  end = RESET)
    print(name)
    
    
#def color_range(name, clist, complement=None):
#    rangelen = len(clist)
#    fore = fg(0) # black pen
#    for i in range(rangelen):
#        code = clist[i]
#        fore = fg(clist[0]) if i >= label('sum', int((rangelen -1) / 2)) else peek(fg(clist[-1]))
#        back = bg(clist[i])
#        print(f"{fore}{back}[{clist[i]:03d}]",  end = RESET)
#    print(f"                                 {name}")

WHITE_BLACK = [231,188,145,102,59,16]
WHITE_RED_BLACK     = [231,224,217,210,203,196,160,124,88,52,16]
WHITE_BLUE_BLACK    = [231,189,147,105,63,21,20,19,18,17,16]
WHITE_GREEN_BLACK   = [231,194,157,120,83,46,40,34,28,22,16]
WHITE_CYAN_BLACK    = [231,195,159,123,87,51,44,37,30,23,16]
WHITE_MAGENTA_BLACK = [231,225,219,213,207,201,164,127,90,53,16]
WHITE_YELLOW_BLACK = [231,230,229,228,227,226,184,142,100,58,16]
GREYS = [231,255,254,253,252,251,250,249,248,247,246,245,244,243,242,241,240,239,238,237,236,235,234,233,232,16]


COLOR_GRID = {
    'red': WHITE_RED_BLACK,
    'blue': WHITE_BLUE_BLACK,
    'green': WHITE_GREEN_BLACK,
    'cyan': WHITE_CYAN_BLACK,
    'magenta': WHITE_MAGENTA_BLACK,
    'yellow': WHITE_YELLOW_BLACK,
    'grey': GREYS
 }

def tone(s, color, tone=0, complement=False):
    size = len(COLOR_GRID[color])
    mid = round(size / 2)
    brightness = mid + int(-tone)
    if brightness < 0:
        brightness = 0
    elif brightness > size:
        brightness = size - 1
    
    fore = fg(COLOR_GRID[color][brightness])
    if complement:
        back = bg(COLOR_GRID[color][0]) if peek(tone >= size / 2) else bg(COLOR_GRID[color][peek(mid + int(tone))]) 
        #back = COLOR_GRID[color][brightness]
        return f"{fore}{back}{s}{RESET}"
    else:    
        return f"{fore}{s}{RESET}"

print()
print_color_range('reds', WHITE_RED_BLACK )
print_color_range('yellows', WHITE_YELLOW_BLACK    )
print_color_range('greens', WHITE_GREEN_BLACK  )
print_color_range('cyans', WHITE_CYAN_BLACK   )
print_color_range('blues', WHITE_BLUE_BLACK   )
print_color_range('magentas', WHITE_MAGENTA_BLACK)
print_color_range('white to black', WHITE_BLACK)
print_color_range('grays', GREYS)
print()

print( '[', tone("brightest red", "red" , 6, True), "]")
print( tone("im %50 brighter",'red',+3, True))
print( tone("this is pure red",'red',0)  )
print( tone("%50 darker red", "red" , -3, True))
print( '[', tone("darkest red", "red" , -6, True), "]")

