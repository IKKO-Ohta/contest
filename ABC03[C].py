

nums = [int(x) for x in input().split()] ; N = nums[0] ; K = nums[1]
rate = [int(x) for x in input().split()]
rates = sorted(rate)

takahashi = 0
for i in range(N-K,N):
	takahashi = (takahashi + rate[i]) / 2

print(takahashi)
