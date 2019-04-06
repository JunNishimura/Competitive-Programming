import math
r = 100000
for i in range(int(input())): r = math.ceil(r*1.05/1000)*1000
print(r)