def GCD(a, b): # a > b
    if a % b == 0: return b
    else: return GCD(b, a%b)
w, h, c = map(int, input().split())
if w > h: g = GCD(w, h)
else: g = GCD(h, w)
print(h*w*c//g**2)