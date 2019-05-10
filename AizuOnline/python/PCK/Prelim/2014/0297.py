n = int(input())
for _ in range(n):
    k, p = map(int, input().split())
    r = k % p
    print(r if r != 0 else p)