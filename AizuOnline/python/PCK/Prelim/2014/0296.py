c = list(map(int, input().split()))
a = [1,5,10,50,100,500]
print(1 if sum([x * y for (x, y) in zip(c, a)]) >= 1000 else 0)