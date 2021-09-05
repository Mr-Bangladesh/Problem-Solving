lim=1005
dp=[0]*lim
dp[0]=1
dp[1]=2
dp[2]=3
for i in range(3,lim):
	dp[i]=dp[i-1]+dp[i-2]

while (True):
	try:
		n=int(input())
		print(dp[n])
	except EOFError:
		break