def f(n,a):
	p=[0]*200
	p[1]=a
	for i in range(2,n+1):
		p[i]=p[i-1]*a
	sum=0
	for i in range(1,n+1):
		sum=sum+i*p[i];
	return sum

while (True):
	try:
		n,m=map(int,input().split())
		print(f(n,m))
	except EOFError:
		break
