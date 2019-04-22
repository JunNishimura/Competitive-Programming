li = input().split()
m = (li[0], 0)
l = (li[0], len(li[0]))
for s in set(li):
    if li.count(s) > m[1]: m = (s, li.count(s))
    if l[1] < len(s): l = (s, len(s))
print(m[0], l[0])
    
    