def myfind(S):
	if (len(S) % 2 == 0):
		dv = len(S)/2
		f,e = S[:dv],S[dv:]
		print(f,e)
		if f == e: return True
	return False

if __name__ == '__main__':
	S = input()
	while !(myfind(S)): 
		S= S[:-1]
	print(len(S))