N = int(input())
boss = {i:[] for i in range(N)}
S = [i for i in range(N)]
for worker in range(1,N):
    bs = int(input()) - 1 
    boss[bs].append(worker)
 
for i in reversed(range(N)):
    MIN,MAX = 10000000,-1
    if not boss[i]: S[i] = 1
    elif len(boss[i]) == 1: S[i] = S[boss[i][0]] * 2 + 1
    else:
        for worker in boss[i]:
            if S[worker] < MIN: MIN = S[worker]
            if S[worker] > MAX: MAX = S[worker]
        S[i] = MAX + MIN + 1
 
 
print(S[0])