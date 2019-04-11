import sys
def PrimNum(p):
    i = 0
    while True:
        if len(l) <= i: break
        if l[i] > p: break
        i+=1
    return i
def PrimeList(p) -> list:
    if p == 2: return 1
    elif p > 2:
        l = list(range(2, p+1))
        i = 0
        while pow(l[i], 2) <= p:
            # 2~pまでの数字の表を作って、2からpに向けて一つずつその倍数となる数を消していく。消されずに残っているものは素数である。
            # 入力の内の最大数のみを取り出して、この関数にかける。他の値はリストの中から
            l = [ l[j] for j in range(0, len(l)) if j <= i or l[j] % l[i] != 0] 
            i+=1
    return l
a = [int(line) for line in sys.stdin]
l = PrimeList(max(a)) # 最大値のみを渡す
for i in a: print(PrimNum(i))