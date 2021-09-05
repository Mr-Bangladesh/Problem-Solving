dp=[0]*1000005
x=1
dp[3]=0
dp[4]=1
dp[5]=3
for i in range(6,1000002):
	if i%2==0:
		x+=1
		y=(x*(x+1))/2
		z=(x*(x-1))/2
		dp[i]=int(y+z) + dp[i-1]
	else:
		y=(x*(x+1))/2
		dp[i]=int(y+y) + dp[i-1]

while True:
	n=int(input())
	if n<3:
		break
	print(dp[n])
	