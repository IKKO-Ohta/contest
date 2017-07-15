# coding: utf-8
# Here your code !
from queue import Queue
 
Aq = Queue()
Bq = Queue()
 
nums = [int(x) for x in input().split()]
N,M = nums[0],nums[1]
nums = [int(x) for x in input().split()]
X,Y = nums[0],nums[1]
 
nums = [int(x) for x in input().split()]
for num in nums: Aq.put(num)
nums = [int(x) for x in input().split()]
for num in nums: Bq.put(num)
 
time = 0
cnt = 0
t = 0
n_flight = -1
 
while(1):
 
    while(1):
        try:
            n_flight = Aq.get(False)
        except:
            print(cnt)
            exit(0)
 
        if n_flight >= time : 
            time = n_flight + X
            break
 
    while(1):
        try:
            n_flight = Bq.get(False)
        except:
            print(cnt)
            exit(0)
 
        if n_flight >= time : 
            time = n_flight + Y
            break
 
    cnt += 1