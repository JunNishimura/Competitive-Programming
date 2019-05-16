N = int(input())
A = list(map(int, input().split()))
i = 1
count = 0
while (sum(A[j] <= 0 for j in range(1, len(A)-1)) != len(A)-2):
    if A[i] > 0:
        if i-1 != 0 or i+1: j = i+1 if A[i+1] > A[i-1] else i-1
        else: j = i+1 if A[i+1] >= A[i-1] else i-1
        A[i] -= 1
        A[j] -= 1
        count += 2
    i += 1
    if i == len(A)-1:
        i = 1
if A[0] > 0: count += A[0]
if A[-1] > 0: count += A[-1]
print(count)