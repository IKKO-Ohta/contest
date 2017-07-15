import math
N = int(input())
depth = math.ceil(math.log2(N))

n = N ; depth = 0
while(n>0):
    n = n // 2
    depth +=1


def solve():
    t = 0
    x = 1

    if depth % 2 == 1:
        while(1):

            if (2*x + 1 > N and 2*x >N):
                return 1 if t % 2 == 1 else -1

            t += 1
            if t % 2 == 1: x = 2*x + 1
            else: x = 2*x
    else:
        while(1):

            if (2*x + 1 > N and 2*x >N):
                return 1 if t % 2 == 1 else -1

            t +=1
            if t % 2 == 1: x = 2*x
            else: x = 2*x + 1

if __name__ == '__main__':
    ans = solve()
    print("depth",depth)
    if ans == 1: print("Takahashi")
    else:print("Aoki")