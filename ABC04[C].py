N = int(input())
cards = ["1","2","3","4","5","6"]
N = N % 120
 
for i in range(N):
	a = i % 5 + 1
	b = i % 5 + 2
	cards[a-1],cards[b-1] = cards[b-1],cards[a-1]
 
print("".join(cards))