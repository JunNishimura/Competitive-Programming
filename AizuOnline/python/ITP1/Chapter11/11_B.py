a = list(map(int, input().split()))
s = ['402351', '152304', '310542', '215043']   

def search(t, _a, _b, _c) -> (bool, list):
    for i in range(len(s)):
        t.append([_a[int(j)] for j in list(s[i])])
        if t[0] == _b and t[1] == _c:
            return True, t
    return False, t

for _ in range(int(input())):
    b, c = map(int, input().split())
    t = []
    t.append(a)
    # print(t)
    # l = -1
    i = 0
    while True:
        if t[i][0] == b and t[i][1] == c:
            print(t[i][2])
            break
        else:
            t.append([])





        k = search(t[0], b, c)
        if k[0] == True:
            print(k[1][2])
            break
        else:
            l+=1
            t = [t[int(j)] for j in list(s[l])]