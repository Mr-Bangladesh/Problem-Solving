cs=1
while True:
	n,m=map(int,input().split())
	if n==0 and m==0:
		break
	x=m-1
	start=int((x*(x+1))/2)
	num=0
	d=start
	sum=0
	for i in range(1,n):
		cur=num+d
		num=cur
		sum+=cur
	print("Case "+str(cs)+": "+str(sum))
	cs+=1