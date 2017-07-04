from collections import deque
"""
pythonには両端キューがあります。
"""

n = int(input())
A = [x for x in input().split()]
B = deque()
 
if n % 2 == 0:
    for i in range(n):
        if i % 2 == 0:
            B.append(A[i])
        else:
            B.appendleft(A[i])
else:
    for i in range(n):
        if i % 2 == 0:
            B.appendleft(A[i])
        else:
            B.append(A[i])
print(" ".join(B))