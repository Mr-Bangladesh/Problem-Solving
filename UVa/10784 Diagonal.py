def diag(n):
	x=n-3
	sum=int((x*(x+1))/2)+x
	return sum

def lower_bound(n):
	l=3
	r=100000000
	while(l<=r):
		mid=int((l+r)/2)
		sum=diag(mid)
		if(sum>=n):
			r=mid-1
		else:
			l=mid+1
	return l

cs=1
while True:
	n=int(input())
	if(n==0):
		break
	ans=lower_bound(n)
	print("Case "+str(cs)+": "+str(ans))
	cs+=1
