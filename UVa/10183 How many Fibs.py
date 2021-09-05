dp=[0]*10000
dp[1]=1
dp[2]=2
for i in range(3,482):
	dp[i]=dp[i-1]+dp[i-2]

def lower_bound(n):
	l=1
	r=481
	while l<=r:
		mid=int((l+r)/2)
		if dp[mid]>=n:
			r=mid-1
		else:
			l=mid+1
	return l
def upper_bound(n):
	l=1
	r=481
	while l<=r:
		mid=int((l+r)/2)
		if dp[mid]>n:
			r=mid-1
		else:
			l=mid+1
	return l

while True:
	n,m=map(int,input().split())
	if n==0 and m==0:
		break
	l=lower_bound(n)
	#print(l)
	r=upper_bound(m)
	#print(r)
	print(r-l)