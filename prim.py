INF = 10000000000
nums = [int(x) for x in input().split()]
N,M = nums[0],nums[1]
d = [[INF, for i in range(N)] for j in range(N)]
used = [False for i in range(N)]

def prim():
	mincost = [INF for i in range(N)]

	mincost[0] = 0
	int res = 0

	while(1):
		int v = -1  # vは議論する頂点
		for u in range(N):
			if !used[u] and (v == -1 or mincost[u] < mincost[v]): v = u

		if v == -1: break  # もう更新されない
		used[v] = True
		res += mincost[v]

		for u in range(N):
			mincost[u] = min(mincost[u],d[v][u])

	return res


if __name__ == '__main__':
	for i in range(M):
		nums = [int(x) for x in input().split()]
		u,v,l = nums[0]-1,nums[1]-1,nums[2]
		d[u][v] = l
		d[v][u] = l

	ans = prim()

	if False in used:
		print(-1)
	else:
		print(ans)


