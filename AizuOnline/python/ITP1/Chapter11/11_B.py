a = list(map(int, input().split()))
s = ['402351', '152304', '310542', '215043']   
for _ in range(int(input())):
    b, c = map(int, input().split())
    t = []
    t.append(a)
    i = 0; j = 0
    while True:
        if t[i][0] == b and t[i][1] == c:
            print(t[i][2])
            break
        if i == len(t)-1: # add if it finishes searching all path
            for h in range(len(s)):
                t.append([ t[j][int(k)] for k in list(s[h]) ])
            j+=1
        i+=1