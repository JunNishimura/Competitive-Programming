# original ver
# moji = input()
# for _ in range(int(input())):
#     s = [i for i in map(str, input().split())]
#     n1 = int(s[1]); n2 = int(s[2])
#     if s[0][0] == "p":
#         print(moji[n1:n2+1])
#     else: 
#         ch = s[3] if s[0][2]=="p" else moji[n1:n2+1][::-1]
#         moji=moji[:n1]+ch+moji[n2+1:]

# revised ver
moji = input()
for _ in range(int(input())):
    s = input().split()
    a, b = map(int, s[1:3]); b+=1
    if s[0][2]=='i': print(moji[a:b])
    elif s[0][2]=='p': moji=moji[:a]+s[3]+moji[b:]
    else: moji=moji[:a]+moji[a:b][::-1]+moji[b:]