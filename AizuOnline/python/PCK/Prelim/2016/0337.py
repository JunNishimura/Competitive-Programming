e, y = map(int, input().split())
if e == 0:
    if y >= 1989: print("H{}".format(y-1988))
    elif y >= 1926: print("S{}".format(y-1925))
    elif y >= 1912: print("T{}".format(y-1911))
    else: print("M{}".format(y-1867))
elif e == 1: # Meiji era
    print(1867+y)
elif e == 2: # Taisho era
    print(1911+y)
elif e == 3: # Showa era
    print(1925+y)
else: # Heisei era
    print(1988+y)