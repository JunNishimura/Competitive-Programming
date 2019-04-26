def SetCount(p):
    if (p > 36): return 0
    
while True:
    try:
        print(SetCount(int(input())))
    except:
        break