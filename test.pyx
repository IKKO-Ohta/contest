n = int(input())
A = [x for x in input().split()]
B = []
 
if n % 2 == 0:
    for i in range(n):
        if i % 2 == 0:
            B.append(A[i])
        else:
            B.insert(0,A[i])
else:
    for i in range(n):
        if i % 2 == 0:
            B.insert(0,A[i])
        else:
            B.append(A[i])
print(" ".join(B))