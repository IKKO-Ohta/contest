
N = int(input())
S = [int(x) for x in input().split()]
ans = - 10000

def dfs(t,i=0):
    if (t == 1):
        res = []
        for j in range(N):
            if j > i: i,j = j,i
            s = S[i:j]
            takahashi = [s[i] for i in range(len(s)) if i % 2 == 0]
            aoki = [s[i] for i in range(len(s)) if i % 2 == 1]
            res.append((sum(takahashi),sum(aoki)))
        res = sorted(res, key=lambda x: x[1])
        return res[0]

    for i in range(N):
        p = dfs(t+1,i)
        ans = max(ans,p[0])
    return ans

if __name__ == '__main__':
    
    ans = dfs(0,0)
    print(ans)
