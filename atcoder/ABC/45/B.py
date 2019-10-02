d = {}
for i in ["a", "b", "c"]:
    d[i] = list(input())
k = "a"
while len(d[k]) > 0:
    k = d[k].pop(0)
print(k.upper())