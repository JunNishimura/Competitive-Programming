# import math
# x1, y1, x2, y2 = map(float, input().split())
# print(math.sqrt( (x2-x1)**2 + (y2-y1)**2 ))

# revise
a,b,c,d=map(float,input().split())
print(abs(complex(c-a,d-b)))