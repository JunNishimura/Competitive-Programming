w, h, n = map(int, input().split())
min_x, min_y = 0, 0
for _ in range(n):
    x, y, a = map(int, input().split())
    if a == 1:
        min_x = max(min_x, x)
    elif a == 2:
        w = min(w, x)
    elif a == 3:
        min_y = max(min_y, y)
    elif a == 4:
        h = min(h, y)

print( (w-min_x)*(h-min_y) if min_x < w and min_y < h else 0)