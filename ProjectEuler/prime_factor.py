import math

def prime_factors(target):
    while target % 2 == 0:
        print (2)
        target = target / 2
    
    for i in range(3, int(math.sqrt(target))+1, 2):
        while target % i == 0:
            print(i)
            target = target / i 

print( prime_factors(600851475143) )