N = list(map(int, input().split()))
N = [ [N[i], N[i+1]] if i % 2 == 1 for i in range(0, 2*N[0]+1) ]
# M = list(map(int, input().split()))
# N += list(map(int, input().split()))
print(N)