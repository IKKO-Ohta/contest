N = int(input())
gold = sum([i*j for i in range(1,10) for j in range(1,10)])
prod = N-gold

res = []
for i in range(1,10):
	if prod % i == 0:
		factor = (i,prod//i)
		if factor[0]<=9 and factor[1]<=9: res.append(factor)
print(res)