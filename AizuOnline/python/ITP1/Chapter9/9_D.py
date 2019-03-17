moji = input()
for _ in range(int(input())):
    s = [i for i in map(str, input().split())]
    n1 = int(s[1]); n2 = int(s[2])
    if s[0][0] == "p":
        print(moji[n1:n2+1])
    else: 
        ch = s[3] if s[0][2]=="p" else moji[n1:n2+1][::-1]
        moji=moji[:n1]+ch+moji[n2+1:]