lim=5000
dp=[0]*lim
dp[1]=1
dp[2]=1
for i in range(3,lim):
	dp[i]=dp[i-1]+dp[i-2]

while (True):
	try:
		n=int(input())
		print(dp[n])
	except EOFError:
		break