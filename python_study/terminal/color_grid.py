#!/bin/env python3

def fg(n):
    assert -1 < n < 256, f"{n} value outside (0,255)"
    return f"\x1b[38;5;{n}m"

def bg(n):
    assert -1 < n < 256, f"{n} value outside (0,255)"
    return f"\x1b[48;5;{n}m"
    
RESET = "\x1b[0m"

print("The 1st 16 colors")

for i in range(0,16):
    print(f"{fg(0)}{bg(i)}[{i:03d}]{bg(0)}" , end = RESET)

print("\nthe rest\n")
for i in range(16,255,6):
    for j in range(0,6):
        print(f"{fg(0)}{bg(i + j)}[{i + j:03d}]", end = RESET)
    print()


