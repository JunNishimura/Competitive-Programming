N = int(input())
l = []
count = 0
for _ in range(N):
    p = set(map(int, input().split()))
    if p in l: count+=1
    else: l.append(p)
print(count)