nums = [int(x) for x in  input().split()]
N,M = nums[0],nums[1]
dp = [[0 for i in range(N+1)] for j in range(M+1)]

for i in range(N+1):
	dp[0][i] = 1
for i in range(M+1):
	dp[i][0] = 1

for i in range(N):
	for j in range(M):
		dp[j+1][i+1] = dp[j+1][i] + dp[j][i+1]

print(dp[M-1][N-1] % 1000000007)

