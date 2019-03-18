while int(input()) != 0:
    a = [int(i) for i in input().split()]
    a = list(map(lambda x: (x-(sum(a)/len(a)))**2, a))
    print((sum(a)/len(a))**.5)