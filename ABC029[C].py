import itertools

N = int(input())
A = ["a","b","c"]
co = [i for i in itertools.product(A, repeat=N)]
for x in co:
	print("".join(list(x)))