"""===========================================================================================
* Name : generate_subsets.py
* Author: taikido
* Description: Algorithm to Generate Subsets.
* Sources: 
*        [1] http://www.bowdoin.edu/~ltoma/teaching/cs210/spring09/Slides/210-recursion2.pdf
*        [2] http://www.bowdoin.edu/~ltoma/teaching/cs210/spring09/Slides/210-recursion2.pdf
* Date: Tues.Dec.10.2013
*============================================================================================="""

"""
sub = gen_subsets
Tree of recursive calls for sub("", "abc")

                                                        sub("", "abc")
                                
                                        sub("a", "bc")                                            sub("", "bc")
                    
                   sub("ab", "c")                  sub("a", "c")                 sub("b", "c")                    sub("", "c")
                  
    sub("abc", "")     sub("ab", "")    sub("ac", "")    sub("a", "")  sub("bc", "")     sub("b", "")       sub("c", "")        sub("", "")
                   
                   
"""


""" Generates subsets of a given set. Uses strings to represent sets/subsets.

    @param so_far: subset element is currently being added to.
    @param rest: set element is taken from.
    @param subsets: list of subsets formed.
"""
def gen_subsets(so_far, rest, subsets):
    if len(rest) == 0:
        subsets.append(so_far)
        #print so_far
    else:
        gen_subsets(so_far+rest[0], rest[1:], subsets) #add to subset, remove from rest, recur
        gen_subsets(so_far, rest[1:], subsets) #don't add to subset, remove from rest, recur
        
        
""" Generates subsets of a given set. Uses tuple to represent sets/subsets.
        *Use tuple instead of list (list is mutable, will produce unfavorable results)

    @param so_far: subset element is currently being added to.
    @param rest: set element is taken from.
    @param subsets: list of subsets formed.
"""
def sub(so_far, rest, subsets):
    if len(rest) == 0:
        subsets.append(so_far)
        
    else:
        sub(so_far + tuple(rest[0]), rest[1:], subsets)        
        sub(so_far, rest[1:], subsets)
        

              
def main():
    
    so_far = ()
    rest = ("a", "b", "c")
    subsets = []
    
    sub(so_far, rest, subsets)
    print "Subsets generated using Tuple Representation are: \n", subsets
    print
    

    so_far = ""
    rest = "1234"
    subsets = []
    gen_subsets(so_far, rest, subsets)
     
    print "Subsets generated using String Representation are: \n", subsets    
    print
    
    #test tuple merging
    t = ("a", "b", "c")
    d = "d"    
    t += tuple(d)    
    print t
    
    
if __name__ == "__main__":
    main()
