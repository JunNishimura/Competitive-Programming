import operator 
n, m, l = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(n)]
B = [list(map(int, input().split())) for _ in range(m)]
C = [[sum(map(operator.mul, tuple(A[i]), list(zip(*B))[j])) for j in range(l) ] for i in range(n) ]
print ('\n'.join([' '.join(map(str,i)) for i in C]))