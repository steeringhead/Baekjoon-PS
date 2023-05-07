import sys
input=sys.stdin.readline


l=int(input())

arr=[]
dp=[]

for _ in range(l):
    arr.append(int(input()))


dp.append(arr[0])

if l>1:

    dp.append(max(arr[0],arr[0]+arr[1]))



if l>2:
    dp.append(max(arr[0]+arr[2],arr[1]+arr[2]))

for i in range(3,l):
    
        
    dp.append(max(dp[i-2]+arr[i],arr[i]+arr[i-1]+dp[i-3]))



print(dp.pop())