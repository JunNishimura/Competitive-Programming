while True:
    s = input()
    if s == '-': break
    for _ in range(int(input())):
        i = int(input())
        s=s[i:]+s[:i]
    print(s)