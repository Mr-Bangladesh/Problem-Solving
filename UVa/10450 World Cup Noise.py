dp=[0]*55
dp[1]=2
dp[2]=3
for i in range(3,52):
	dp[i]=dp[i-1]+dp[i-2]

t=int(input())
for cs in range(1,t+1):
	n=int(input())
	print("Scenario #"+str(cs)+":\n"+str(dp[n])+'\n')
