a = list(map(int, input().split()))
s = ['402351', '152304', '310542', '215043']      

for _ in range(int(input())):
    b, c = map(int, input().split())
    i = 0; 
    while True:
        t = [a[int(j)] for j in list(s[i])]
        if t[0] == b and t[1] == c:
            break
        i+=1
        if i == len(s):
            
    print(t[2])