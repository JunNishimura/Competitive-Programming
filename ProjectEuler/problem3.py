def Solve(target):
    if target == 1: return
    id = 0
    while True:
        if target % prime_list[id] == 0:
            target = target // prime_list[id]
            prime_factors.append(prime_list[id])
            Solve(target)
            return 
        id = id+1
        if id >= prime_list.count:
            break

def Sieving(x, li:list):
    s = x * x
    while True:
        if s > 100: break
        if s in li: li.remove(s)
        s += x

def Sieve_of_Eratosthenes(li:list):
    j = 0
    while True:
        if li[j]*li[j] > 100: break
        Sieving(li[j], li)
        j = j+1


prime_factors = []
prime_list = list(range(2,101))
Sieve_of_Eratosthenes(prime_list)

print(prime_list)