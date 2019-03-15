import sys
w = input()
print (sum([ i.split(' ').count(w) for i in sys.stdin.read().lower().split('\n')]))