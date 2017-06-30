import math
import numpy as np

nums = [int(x) for x in input().split()]
A = (nums[0],nums[1])
B = (nums[2],nums[3])
C = (nums[4],nums[5])

alpha = np.asarray([B[0] - A[0], B[1] - A[1]])
beta  = np.asarray([C[0] - A[0], C[1] - A[1]])

S = 0.5 * math.sqrt(
	np.linalg.norm(alpha) ** 2 * np.linalg.norm(beta) ** 2 - alpha.dot(beta) ** 2 
	)

print(S)