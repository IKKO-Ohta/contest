from fractions import gcd
nums = [int(x) for x in input().split()]
 
def ngcd(nums):
	d = 0
	for num in nums:
		d = gcd(d,num)
	return d
 
 
t = ngcd(nums)
if t != 1:
	nums = [int(num / t) for num in nums]
 
t = gcd(nums[0],nums[1])
if t == 1:
    print('YES')
else:
    print('NO')