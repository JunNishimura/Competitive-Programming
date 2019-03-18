n = input()
a = list(map(int, input().split()))
b = list(map(int, input().split()))
for i in range(1, 5):
    if i==4: print(max(list(map(lambda x,y: abs(x-y), a, b))))
    else: print(sum(list(map(lambda x,y: abs(x-y)**i, a, b)))**(1/i))
