st = []
while 1:
    try:
        x = int(input())
        st.append(x) if x != 0 else print(st.pop())
    except EOFError:
        break