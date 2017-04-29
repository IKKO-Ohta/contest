import sys

s = input() #['ringo', 'gorira', 'apple']

def isSeritori(A,B):
    print(A[-1],B[0])
    if A[-1] == B[0] :
        return True
    else:
        return False

for i in range(2):
    if (isSeritori(s[i],s[i+1])):
        continue
    else:
        print('NO')
        sys.exit(0)
print('YES')