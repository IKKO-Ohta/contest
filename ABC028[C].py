import itertools

S = [int(x) for x in input().split()]
C = list(itertools.combinations(S,3))
c = [sum(x) for x in C]
print(c[-3])