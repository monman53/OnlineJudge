N = int(input())
V = [int(i) for i in input().split()]
C = [int(i) for i in input().split()]
 
max = 0
for bit in range(2**N):
    sum = 0
    count = 0
    for i in range(N):
        if (bit >> i) & 1:
            sum += V[i]-C[i]
        else:
            pass

    if sum > max:
        max = sum
 
print(max)
