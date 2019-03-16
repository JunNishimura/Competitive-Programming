ts = 0; hs = 0
for _ in range(int(input())):
    t, h = input().split()
    if t>h: ts+=3
    elif t<h: hs+=3
    elif t==h: ts+=1; hs+=1
print(ts, hs)