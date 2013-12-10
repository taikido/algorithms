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
def gen_subsets(so_far, rest, subsets):
    if len(rest) == 0:
        subsets.append(so_far)
        print so_far
    else:
        gen_subsets(so_far+rest[0], rest[1:], subsets) #add to subset, remove from rest, recur
        gen_subsets(so_far, rest[1:], subsets) #don't add to subset, remove from rest, recur
        
        
def main():
    so_far = ""
    rest = "abc"
    subsets = []
    gen_subsets(so_far, rest, subsets)
    
    print "Subsets generated are: ", subsets
    
    
if __name__ == "__main__":
    main()