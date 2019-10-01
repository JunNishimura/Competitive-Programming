n, k = map(int, input().split())
t = list(input().split())

while True:
    m = str(n) # 文字列に変換
    found = True
    for i in range(len(m)):
        if m[i] in t:
            found = False
    if found: break
    n += 1
print(n)
        