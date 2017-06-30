# coding: utf-8
pairs = set()

def solve(piece,others):
    for q in others:
        if piece == q: continue
        if piece[0] == q[0] or piece[1] == q[1] or float((piece[1] - q[1])) / (piece[0]-q[0]) == 1 or float((piece[1] - q[1])) / (piece[0]-q[0]) == -1 : 
            pair = (piece,q)
            if not (q,piece) in pairs:
                pairs.add(pair)
    return

if __name__ == '__main__':
    queens = []
    N = int(raw_input())
    for i in range(N):
        queen = tuple([int(x) for x in raw_input().split()])
        queens.append(queen)
    man = queens[:]
    cnt = 0 ; lim = N/2 + 1 
    for queen in queens:
        solve(queen,man)
        cnt +=1
        if lim < cnt: break 

    print len(pairs)