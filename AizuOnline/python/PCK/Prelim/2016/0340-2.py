N = int(input())
A = list(map(int, input().split()))
i = 1
count = 0
print(A)
while (sum(list(A[j] <= 0 for j in range(1, len(A)-1))) != len(A)-2):
    if A[i] == 0:
        
    elif i == 1 and A[2] > 0: 
        A[1] -= 1; A[2] -= 1; count += 2
    elif i == len(A)-2 and A[i-1] > 0:
        A[i-1] -= 1; A[i] -= 1; count += 2
    else: 
        k = i+1 if A[i+1] > A[i-1] else i-1
        A[i] -= 1; A[k] -= 1; count += 2
    i += 1
    print(A)
    print("count: {}".format(count))
    if i == len(A)-1:
        i = 1
if A[0]  > 0: count += A[0]
if A[-1] > 0: count += A[-1]
print(count) 