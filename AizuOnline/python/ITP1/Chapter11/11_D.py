def search_same(a, b): 
    i = 0
    while a[i] == b[i] and a[i+1] == b[i+1]:
        i+=1
    return i

def search(id) -> bool: # retun true if there is same set
    t = []
    t.append(a[id])
    i = 0; j = 0
    k = id
    while True:
        k+=1
        if k == len(a): return False
        if len(set(t[i]) ^ set(a[k])) != 0: continue
        while True:
            if t[i][0] == a[k][0] and t[i][1] == a[k][1]:
                if t[i][2] == a[k][2] and t[i][3] == a[k][3] and t[i][4] == a[k][4] and t[i][5] == a[k][5]: 
                    print("hit")
                    return True
                else: break
            if i == len(t)-1: # add if it finishes searching all path
                for h in s:
                    t.append([ t[j][int(l)] for l in list(h) ])
                j+=1
            i+=1
        i=0

a = []
for _ in range(int(input())):
    a.append(list(map(int, input().split())))
s = ['402351', '152304', '310542', '215043']   
b = 0
while True: 
    if b == len(a)-1: 
        print("Yes")
        break
    if search(b):
        print("No")
        break
    b+=1

# def search(l, id):
#     t = [] # list to search
#     target = 1
#     for i in range(id+1, 7):
#         if len(set(l[id]) ^ set(l[i]))== 0: t.append(l[i])
#         else: continue

# a = []
# for _ in range(int(input())):
#     a.append(set(map(int, input().split())))