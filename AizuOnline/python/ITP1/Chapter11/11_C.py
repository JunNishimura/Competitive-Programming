a = list(map(int, input().split()))
b = list(map(int, input().split()))
s = ['402351', '152304', '310542', '215043']   
t = []
t.append(a)
i = 0; j = 0
while True:
    if t[i][0] == b[0] and t[i][1] == b[1]:
        ans = "Yes" if t[i][2] == b[2] and t[i][3] == b[3] else "No"
        print(ans)
        break
    if i == len(t)-1: # add if it finishes searching all path
        for h in range(len(s)):
            t.append([ t[j][int(k)] for k in list(s[h]) ])
        j+=1
    i+=1