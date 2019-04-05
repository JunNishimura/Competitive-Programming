# def search(id) -> bool: # retun true if there is same set
#     t = []
#     t.append(a[id])
#     i = 0; j = 0
#     k = id
#     while True:
#         k+=1
#         if k == len(a): return False 
#         if len(set(t[i]) ^ set(a[k])) != 0: continue # 差集合に値があるなら、すなわち回転しても合致しない
#         while True:
#             cnt = [l for l in range(0, 6) if t[i][l] == a[k][l]]
#             if len(cnt) == 6: return True
#             elif len(cnt) == 4 and len(set(t[i])) == 6:
#                 if set(cnt) == {0,5} or set(cnt) == {2,3} or set(cnt) == {1,4} : return True
#                 else: break
#             elif len(cnt) == 2:
#                 if set(cnt) == {1,4}:
#                     if t[i][0] == a[k][5] and t[i][5] == a[k][0] and t[i][2] == a[k][3] and t[i][3] == a[k][2]: return True
#                 elif set(cnt) == {2,3}:
#                     if t[i][0] == a[k][5] and t[i][5] == a[k][0] and t[i][0] == a[k][5] and t[i][5] == a[k][0]: return True
#                 else: break
#             else: 
#                 if 
#             if i == len(t)-1: # add if it finishes searching all path
#                 for h in s:
#                     t.append([ t[j][int(l)] for l in list(h) ])
#                 j+=1
#             i+=1
#         i=0

# a = []
# for _ in range(int(input())):
#     a.append(list(map(int, input().split())))
# s = ['310542', '215043', '402351', '152304']  # 東西南北
# b = 0
# while True: 
#     if b == len(a)-1: # すべて異なればYES
#         print("Yes")
#         break
#     if search(b): # 同じものがあればNO
#         print("No")
#         break
#     b+=1

def rotate(id, l)->list:
    dir = ['S', '', 'WS', 'ES', 'SS', 'N']
    for o in dir[id]:
        l = [ l[int(k)] for k in list(s[o])]
    return l 

def search(j, i):
    lj = a[j]
    li = a[i]
    if len(set(lj) ^ set(li)) == 0: # 差集合が0ならそもそも面に書かれた値は同じ
        at = 0
        for l in range(6): 
            if lj.count(lj[l]) == 1: # 被りのないインデックスをljから探す
                at = l
                break
        bt = li.index(lj[at]) # target index for the list of comparison
        lj = rotate(at, lj) # target indexを正面に
        li = rotate(bt, li)
        for o in 'EEEE':
            lj = [ lj[int(k)] for k in list(s[o]) ]
            if li == lj: return True
    else: return False

# サイコロの面の値がすべて異なればYes、同じものがあればNo
# 姿勢としては同じものが出るかを探し出すアルゴリズムを構築する。それに引っかからなければすなわちYesとなる
s = {'E': '310542', 'W': '215043', 'S': '402351', 'N': '152304'}  # 東西南北
a = []
n = int(input())
i = 0
while i < n:
    a.append(list(map(int, input().split())))
    j = 0
    # a[0] ~ a[i-1]の面とa[i]を毎回比べる
    while j <= i-1: 
        if search(j, i): 
            print('No')
            i = n
            break 
        j+=1
    if i == n-1: print('Yes')
    i+=1