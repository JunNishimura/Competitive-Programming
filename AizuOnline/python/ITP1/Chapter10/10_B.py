import math
a,b,c = map(int, input().split())
c = c/180*math.pi
h = math.sin(c) * b
S = a * h / 2
L = a + b + abs(complex(a-math.cos(c)*b, h))
print (S, L, h)