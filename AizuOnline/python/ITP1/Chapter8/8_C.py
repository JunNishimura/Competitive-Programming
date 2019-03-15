import sys
moji = sys.stdin.read().lower()
for i in range(97, 97+26): print(f'{chr(i)} : {moji.count(chr(i))}')