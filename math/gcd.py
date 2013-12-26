def gcd_naive(a, b):
    for i in range(min(a,b), 0, -1):
        if a % i == 0 and b % i == 0:
            return i
        
def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)
    
print gcd_naive(48, 18)
print gcd(48, 18)