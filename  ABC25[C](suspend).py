B = []
for i in range(2)
	nums = [int(x) for x in input().split()]
	B.append(nums)
C = []
for i in range(3)
	nums = [int(x) for x in input().split()]
	C.append(nums)

field = [["none" for i in range(3)] for j in range(3)]
field = [["b","a","b"],["a","a","b"],["a","b","a"]]

def eval(f):
	ans = 0
	for i in range(2):
		for j in range(3):
			ans += B[i][j] if f[i][j] == f[i+1][j] else 0
	for i in range(3):
		for j in range(2):
			ans += C[i][j] if f[i][j] == f[i][j+1] else 0
	return ans

def dfs(t=0,f):
	if t == 9:
		return eval(f)
	else:
		for i in range(3):
			for j in range(3):
				if fi[i][j] == "none":  
					fi = f[:]
					fi[i][j] = "a" if t %= 2 else "b"
					t += 1
					
print(eval())