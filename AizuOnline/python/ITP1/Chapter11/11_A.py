a = list(map(int, input().split()))
s = {'S': '402351', 'N': '152304', 'E': '310542', 'W': '215043'}
o = list(input())
for i in o: a = [a[int(j)] for j in list(s[i])]
print (a[0])
