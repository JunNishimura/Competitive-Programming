while 1:
    num = input()
    if int(num) == 0: break
    print(sum(map(int, list(num))))