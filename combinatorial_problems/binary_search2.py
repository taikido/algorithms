"""===========================================================================================
* Name : binary_search.py
* Author: taikido
* Description: Algorithm to perform Binary Search on a Sorted Sequence.
* Sources: 
*        [1] http://community.topcoder.com/tc?module=Static&d1=tutorials&d2=binarySearch
* Date Created: Sun.Jan.5.2014
* Date Last Modified: Fri.Jan.10.2014
*============================================================================================="""

""" Searches for a target value in a sorted sequence using the Binary Search Algorithm (Recursive Approach).

    @param seq: sorted sequence of elements.
    @param target: target value to search for.
    @param low: lowest index in the sequence to start searching from.
    @param high: highest index in the sequence to stop searching at.
    @return index at which target was found.
"""
def binary_search_recursive(seq, target, low, high):
    if low > high:
        return -1
    
    mid = (low + high)/2    
    #print "mid: {0}, seq[mid]: {1}".format(mid, seq[mid])
    if seq[mid] == target:
        return mid
    elif target < seq[mid]:
        return binary_search_recursive(seq, target, low, mid-1)
    else:
        return binary_search_recursive(seq, target, mid+1, high)
    
""" Searches for a target value in a sorted sequence using the Binary Search Algorithm (Iterative Approach).

    @param seq: sorted sequence of elements.
    @param target: target value to search for.
    @return index at which target was found.
"""    
def binary_search_iterative(seq, target):
    low, high = 0, len(seq)
    
    while low < high:
        mid = (low + high)/2 
        if seq[mid] == target:
            return mid    
        elif target < seq[mid]:
            high = mid - 1
        else:
            low = mid + 1
            
    return -1 #target not found

""" Predicate used in binary search: is seq[i] i.e. x >= target. """
def p(x, target):
    return True if x >= target else False
    
    
""" Searches for a target value in a sorted sequence using the Binary Search Algorithm (Iterative Approach).
    Uses the main theorem

    @param seq: sorted sequence of elements.
    @param target: target value to search for.
    @return index at which target was found.
"""    
def binary_search(seq, target):
    low, high = 0, len(seq)-1 #high must = len(seq)-1 to work on edge cases
    
    while low < high:
        mid = (low + high)/2 
        if p(seq[mid], target) == True:
            high = mid
        else:
            low = mid + 1
    
    print "low: ", low
    if p(seq[low], target) == False:
        print "p(x) is false for all x in seq"
        return -1
            
    return low #low is the least x for which p(x) is true.


""" Searches for a target value  (real #) in a sorted sequence using the Binary Search Algorithm (Iterative Approach).
    Uses the main theorem introduced in TopCoder Allgorithms Tutorial.

    @param seq: sorted sequence of elements.
    @param target: target value to search for.
    @return index at which target was found.
    
    Example sequence
    
    seq = [1.0 5.3 7.8 10.2]
    target = 6.1
    predicate [no no yes yes]
    
"""    
def binary_search_real(seq, target):
    low, high = 0, len(seq)-1 #high must = len(seq)-1 to work on edge cases
    
    max_steps = 10
    steps = 0
    
    while steps < max_steps:
        mid = (low + high)/2 
        if p(seq[mid], target) == True:
            high = mid
        else:
            low = mid 
            
        steps += 1
    
    print "low: {0}, val: {1} ".format(low, seq[low])
    

            
    return low #lo is close to the border between no and yes

def test_bsr():
    seq = [1.0, 5.3, 7.8, 10.2]
    target = 6.1
    binary_search_real(seq, target)

def test():
    seq = [1, 2]
    target = 2
    print binary_search(seq, target)
    
    
if __name__ == "__main__":
    test_bsr()
#     test()
    seq = [0, 5, 13, 19, 22, 41, 55, 68, 72, 81, 98]
     
    #Test Case 1: Test Edge Case - Target = 0
    print binary_search_recursive(seq, 0, 0, len(seq))
    print binary_search_iterative(seq, 0)
    print
     
    #Test Case 2: Test Edge Case - Target = 98
    print binary_search_recursive(seq, 98, 0, len(seq))
    print binary_search_iterative(seq, 98)  
    print 
     
    #Test Case 3: Target = 55
    print binary_search_recursive(seq, 55, 0, len(seq))
    print binary_search_iterative(seq, 55)    
    print binary_search(seq,100)
    
    
    
        
