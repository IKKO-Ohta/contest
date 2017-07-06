# coding: utf-8
nums=[int(x) for x in input().split()]
V,E = nums[0],nums[1]
graph = {x:[] for x in range(V)}
for i in range(E):
    nums=[int(x) for x in input().split()]
    a,b = nums[0]-1,nums[1]-1
    graph[a].append(b)
    graph[b].append(a)

def solve(person):
    """
    ある人について、”友達の友達”を調べる
    """
    friends = graph[person]
    fof = ()
    for friend in friends:
        for ff in graph[friend]:
            fof.add(ff)
    [ff.remove(friend) for friend in friends]
    ff.remove(person)
    return len(ff)


if __name__ == '__main__':
    for p in graph.keys():
        ans = solve(int(p))
        print(ans)

