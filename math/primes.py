"""===========================================================================================
* Name : primes.py
* Author: taikido
* Description: Prime number tutorial/revision.
* Sources: 
*        [1] http://community.topcoder.com/tc?module=Static&d1=tutorials&d2=math_for_topcoders
* Date: Mon.Dec.23.2013
*============================================================================================="""

from math import sqrt

""" Implements Sieve of Eratosthenes to generate all prime numbers from 1 to n.

    @param n: primes generated up to n.
    @return sequence of primes up to n.
"""
def sieve(n):
    is_prime = [True] * n
    is_prime[0], is_prime[1] = False, False
    
    m = int(sqrt(n) + 1)
    for p in range(2, m):
        if is_prime[p]:
            j = 2
            while (p *j < n):
                is_prime[p*j] = False
                j += 1
                
    print is_prime
    
    primes = [i for i in range( n) if is_prime[i]  ]
    print primes

""" Tests if a number, n, is prime (basic/naive method).

    @param n: number to determine primality of.
    @return True if n is prime, False otherwise.
"""
def is_prime(n):
    if n < 2:
        return False
    
    if n == 2:
        return True
    
    if n % 2 == 0:
        return False    

    m = int(sqrt(n)+1)
    for i in range(3, m, 2):
        if n % i == 0:
            return False
        
    return True

""" Tests if a sequence of numbers is prime or not prime. """
def test_primality():
    nums = [1, 2, 3, 15, 17, 311]
    
    for i in nums:
        print "[{0}] prime? - {1}".format(i, is_prime(i))




if __name__ == "__main__":
    sieve(100)
    #test_primality()