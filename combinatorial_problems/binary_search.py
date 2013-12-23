"""===========================================================================================
* Name : binary_search.py
* Author: taikido
* Description: Algorithm to perform Binary Search on a Sorted Sequence.
* Sources: 
*        [1] http://community.topcoder.com/tc?module=Static&d1=tutorials&d2=binarySearch
* Date: Thurs.Dec.12.2013
*============================================================================================="""

""" Searches for a target value in a sorted sequence using the Binary Search Algorithm (Recursive).

    @param seq: sorted sequence of elements.
    @param target: target value to search for.
    @param low: lowest index in the sequence to start searching from.
    @param high: highest index in the sequence to stop searching at.
    @return index at which target was found.
"""
def binary_search(seq, target, low, high): 
    if low > high:
        return -1
    
    mid = (low + high)/2  #low + (high-low)/2         (low + high)/2
    if seq[mid] == target:
        return mid
    elif target < seq[mid]:
        return binary_search(seq, target, low, mid-1)
    else:
        return binary_search(seq, target, mid+1, high)

        
def binary_search_iterative(seq, target):
    low, high = 0, len(seq) #high needs to be len(seq) not len(seq)-1 to work for boundary cases
    while low < high:
        mid = (low+high)/2
        if target == seq[mid]:
            return mid
        elif target < seq[mid]:
            high = mid - 1
        else:
            low = mid + 1         

    #target not found
       
if __name__ == "__main__":
    seq = range(3, 15)
    
    #Test 1
    target = 11
    index = binary_search(seq, target, 0, len(seq)-1)
    print "target: [{0}] is at index: [{1}] in seq: {2}".format(target, index, seq )
    index = binary_search_iterative(seq, target)
    print "target: [{0}] is at index: [{1}] in seq: {2}".format(target, index, seq )
    print
    
    #Test 2
    target = 3
    index = binary_search(seq, target, 0, len(seq)-1)
    print "target: [{0}] is at index: [{1}] in seq: {2}".format(target, index, seq )
    index = binary_search_iterative(seq, target)
    print "target: [{0}] is at index: [{1}] in seq: {2}".format(target, index, seq )
    print
    
    #Test 3
    target = 14
    index = binary_search(seq, target, 0, len(seq)-1)
    print "target: [{0}] is at index: [{1}] in seq: {2}".format(target, index, seq )
    index = binary_search_iterative(seq, target)
    print "target: [{0}] is at index: [{1}] in seq: {2}".format(target, index, seq )
