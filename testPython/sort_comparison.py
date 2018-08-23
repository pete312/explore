#!/usr/bin/python

# Comparisons of sorting
# localhost$ ./sort_comparison.py
# compare running times of bubble sort, quick sort, and merge sort routines
# Enter number of elements to test: 500000
# Do you really want to test bubble with 500000 elements
# n
# quick sort of  500000 numbers is 15.8373019695 seconds
# merge sort of  500000 numbers is 3.40518093109 seconds


# merge sort

import random
import timeit
import sys

# dont remember where I got merge sort code from 
def merge(left, right):
    result = []
    left_idx, right_idx = 0, 0
    while left_idx < len(left) and right_idx < len(right):
        # change the direction of this comparison to change the direction of the sort
        if left[left_idx] <= right[right_idx]:
            result.append(left[left_idx])
            left_idx += 1
        else:
            result.append(right[right_idx])
            right_idx += 1

    if left:
        result.extend(left[left_idx:])
    if right:
        result.extend(right[right_idx:])
    return result

def merge_sort(d):
    if len(d) <= 1:
        return d

    middle = len(d) // 2
    left = d[:middle]
    right = d[middle:]

    left = merge_sort(left)
    right = merge_sort(right)
    return list(merge(left, right)) 
    
# my variation on a common bubble sort pattern 
def bubble_sort(d, destructive=False):
    if not destructive:
        # preserve the original dataset by making a copy of it
        d = [i for i in d] 
    for n in range(len(d)-1,0,-1):
        for i in range(n):
            if d[i]>d[i+1]:
                temp = d[i]
                d[i] = d[i+1]
                d[i+1] = temp
    return d
                

def quicksort(x, destructive=False):
    ''' from https://gist.github.com/anirudhjayaraman/897ca0d97a249180a48b50d62c87f239 
        This code breaks down too many recursions at large ranges of 1000000 items 
    '''
    if not destructive:
        # preserve the original dataset by making a copy of it
        x = [i for i in x]
    
    if len(x) == 1 or len(x) == 0:
        return x
    else:
        pivot = x[0]
        i = 0
        for j in range(len(x)-1):
            if x[j+1] < pivot:
                x[j+1],x[i+1] = x[i+1], x[j+1]
                i += 1
        x[0],x[i] = x[i],x[0]
        first_part = quicksort(x[:i])
        second_part = quicksort(x[i+1:])
        first_part.append(x[i])
        return first_part + second_part
                

def usage():
    print "Usage: %s <number of elements to sort>" % (sys.argv[0])
    print " compare running times of bubble sort, quick sort, and merge sort routines"
        
if __name__ == "__main__":
    
    print "compare running times of bubble sort, quick sort, and merge sort routines"
    print "try values of 10000 with bubble and 500000 with quick and merge"
    count = 0
    while True:
        print "Enter number of elements to test:",
        count = raw_input()
        try:
            count = int(count)
            break
        except ValueError:
            print "non numeric value. ctrl c to abort"
            pass
    
    data = [ int(random.random() * 1000) for i in range(count)]    
    bubble_skip = False
    if count > 10000:
        print "Do you really want to test bubble with %s elements" % count
        if raw_input()[0].lower() != 'y':
            bubble_skip = True
            
            
    if bubble_skip is False:    
        print "bubble sort of %s numbers is %s seconds" % (len(data),timeit.timeit("bubble_sort( data )", setup="from __main__ import bubble_sort, data", number=1))
    
    print "quick sort of  %s numbers is %s seconds" % (len(data), timeit.timeit("quicksort( data )", setup="from __main__ import quicksort, data", number=1))
    
    print "merge sort of  %s numbers is %s seconds" % (len(data), timeit.timeit("merge_sort( data )", setup="from __main__ import merge_sort, data", number=1))



