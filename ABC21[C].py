# coding: utf-8
# Here your code !
INF = 10000000000
N = int(input())
nums = [int(x) for x in input().split()]
a,b = nums[0]-1,nums[1]-1
d = [[INF if i != j else 0 for i in range(N)] for j in range(N)]
roots = [0 for i in range(N)]
MOD = 1000000007
 
def wf():
    for i in range(N):
        for x in range(N):
            for y in range(N):
                d[x][y] = min(d[x][y],d[x][i]+d[i][y])
    return
 
if __name__ == '__main__':
    
    M = int(input())
    for i in range(M):
        nums = [int(x) for x in input().split()]
        x,y = nums[0]-1,nums[1]-1
        d[x][y] = 1; d[y][x] = 1
 
    wf()
    
    """
    いま、wf()によって全点への最短距離の行列dがあたえられている。
    これを用いて、root[Target]を求めよう。
    ワーシャルフロイドに似た考えを用いる。すなわち
    スタート地点から見て、ある地点curveを経由して、Targetに辿り着くと考える。
    このときcurveとTargetが道で繋がっているので、d[curve][Target]は１であるはずだ。
    以上より、curveを全点で総当たりして、条件を満たすようなcurveについて、...(1)
    root[Target] += root[curve]
    とすれば、root[Target]は求まる。
    また、漸化式としての性質上、targetは前から順々に遷移していく必要があることもわかる。...(2)

    いちばん最初のループについて。
    この行列をみていくときに、全ての行列要素について検討する必要はない(targetをAに近いところから議論していくので)。
    すなわち、最初は0の要素を、次は1の要素を、次は2の要素を...というふうにみればよい。 ...(3)
    """
    roots[a] = 1
    for i in range(N): # ...(3)
        for cur in range(N):  # ...(1)
            if d[a][cur] != i:
                continue
            for tar in range(N):  # ...(2)
                if d[a][tar] == i+1 and d[cur][tar] == 1:
                    roots[tar] += roots[cur]
                    roots[tar] %= MOD
 
    print(roots[b])