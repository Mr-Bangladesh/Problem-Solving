// Problem: Palindrome Query I
// Contest: Toph
// URL: https://toph.co/p/palindrome-query-i
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

/**In the name of Allah, the Most Merciful, the Most Merciful.**/
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable" 
#pragma GCC diagnostic ignored "-Wformat"
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;
#define INF 9223372036854775806
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define PI 2*acos(0.0)
#define EPS 1e-9
#define maxn 100005
#define base 89
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//order_of_key,find_by_order
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}
void FastIO(){
	ios_base :: sync_with_stdio (false);
  	cin.tie(0);
	cout.precision(20);
}
struct node{
	ll hashval,cnt;
};
char str[maxn],str1[maxn];
node t[4*maxn],t1[4*maxn];
ll power[maxn];
int len;
void build(int n=1,int b=1,int e=len){
	if(b==e){
		t[n].hashval=str[b-1]-96;
		t[n].cnt=1;
		
		t1[n].hashval=str1[b-1]-96;
		t1[n].cnt=1;
		return;
	}
	int mid=(b+e)/2;
	build(n*2,b,mid);
	build(n*2+1,mid+1,e);
	ll tmp=(t[n*2].hashval*power[t[n*2+1].cnt]+t[n*2+1].hashval)%MOD;
	t[n].hashval=tmp;
	t[n].cnt=t[n*2].cnt+t[n*2+1].cnt;
	
	tmp=(t1[n*2].hashval*power[t1[n*2+1].cnt]+t1[n*2+1].hashval)%MOD;
	t1[n].hashval=tmp;
	t1[n].cnt=t1[n*2].cnt+t1[n*2+1].cnt;
	//cout<<n<<" "<<b<<" "<<t[n].hashval<<endl;
	//cout<<n<<" "<<b<<" "<<e<<" "<<t[n].cnt<<" "<<t[n*2].cnt<<" "<<t[n*2+1].cnt<<endl;
}

int getpos(int k,int n=1,int b=1,int e=len){
	//cout<<n<<" "<<b<<" "<<e<<" "<<k<<endl;
	if(b==e){
		return b;
	}
	int mid=(b+e)/2;
	//cout<<n<<" "<<b<<" "<<e<<" "<<k<<" "<<t[n].cnt<<" "<<t[n*2].cnt<<" "<<t[n*2+1].cnt<<endl;
	if(t[n*2].cnt>=k){
		return getpos(k,n*2,b,mid);
	}
	else{
		return getpos(k-t[n*2].cnt,n*2+1,mid+1,e);
	}
}
int getpos1(int k,int n=1,int b=1,int e=len){
	//cout<<n<<" "<<b<<" "<<e<<" "<<k<<endl;
	if(b==e){
		return b;
	}
	int mid=(b+e)/2;
	//cout<<n<<" "<<b<<" "<<e<<" "<<k<<" "<<t1[n].cnt<<" "<<t1[n*2].cnt<<" "<<t1[n*2+1].cnt<<endl;
	if(t1[n*2+1].cnt>=k){
		return getpos1(k,n*2+1,mid+1,e);
	}
	else{
		return getpos1(k-t1[n*2+1].cnt,n*2,b,mid);
	}
}

void update(int n,int b,int e,int idx,char ch){
	//cout<<n<<" "<<b<<" "<<e<<" "<<idx<<" "<<ch<<endl;
	if(b>idx || e<idx) return;
	if(b==e){
		//cout<<"update "<<n<<" "<<b<<" "<<idx<<endl;
		if(ch=='*'){
			t[n].cnt=0;
			t[n].hashval=0;
		}
		else{
			t[n].hashval=(ch-96);
		}
		return;
	}
	int mid=(b+e)/2;
	//if(t[n*2].cnt>=idx){
		update(n*2,b,mid,idx,ch);
	//}
	//else{
		update(n*2+1,mid+1,e,idx,ch);
	//}
	if(t[n*2].cnt==0){
		t[n]=t[n*2+1];
	}
	else if(t[n*2+1].cnt==0){
		t[n]=t[n*2];
	}
	else{
		ll tmp=(t[n*2].hashval*power[t[n*2+1].cnt]+t[n*2+1].hashval)%MOD;
		t[n].hashval=tmp;
		t[n].cnt=t[n*2].cnt+t[n*2+1].cnt;
	}
}

void update1(int n,int b,int e,int idx,char ch){
	if(b>idx || e<idx) return;
	if(b==e){
		if(ch=='*'){
			t1[n].cnt=0;
			t1[n].hashval=0;
		}
		else{
			t1[n].hashval=(ch-96);
		}
		return;
	}
	int mid=(b+e)/2;
	//if(t1[n*2].cnt>=idx){
		update1(n*2,b,mid,idx,ch);
	//}
	//else{
		update1(n*2+1,mid+1,e,idx,ch);
	//}
	if(t1[n*2].cnt==0){
		t1[n]=t1[n*2+1];
	}
	else if(t1[n*2+1].cnt==0){
		t1[n]=t1[n*2];
	}
	else{
		ll tmp=(t1[n*2].hashval*power[t1[n*2+1].cnt]+t1[n*2+1].hashval)%MOD;
		t1[n].hashval=tmp;
		t1[n].cnt=t1[n*2].cnt+t1[n*2+1].cnt;
	}
	//cout<<"U "<<n<<" "<<b<<" "<<e<<" "<<t1[n].hashval<<" "<<t1[n].cnt<<endl;
}

node query(int n,int b,int e,int i,int j){
	if(e<i || b>j){
		node e;
		e.hashval=0; e.cnt=0;
		return e;
	}
	//cout<<n<<" "<<b<<" "<<e<<" "<<t[n].hashval<<endl;
	if(b>=i && e<=j){
		return t[n];
	}
	int mid=(b+e)/2;
	node x=query(n*2,b,mid,i,j);
	node y=query(n*2+1,mid+1,e,i,j);
	//cout<<n<<" "<<b<<" "<<e<<" "<<x.hashval<<" "<<y.hashval<<endl;
	node ans;
	if(x.cnt==0){
		ans=y;
	}
	else if(y.cnt==0){
		ans=x;
	}
	else{
		ll tmp=(x.hashval*power[y.cnt]+y.hashval)%MOD;
		ans.hashval=tmp;
		ans.cnt=x.cnt+y.cnt;
	}
	
	//cout<<n<<" "<<b<<" "<<e<<" "<<ans.hashval<<" "<<ans.cnt<<endl;
	return ans;
}

node query1(int n,int b,int e,int i,int j){
	if(e<i || b>j){
		node e;
		e.hashval=0; e.cnt=0;
		return e;
	}
	if(b>=i && e<=j){
		return t1[n];
	}
	int mid=(b+e)/2;
	node x=query1(n*2,b,mid,i,j);
	node y=query1(n*2+1,mid+1,e,i,j);
	
	node ans;
	if(x.cnt==0){
		ans=y;
	}
	else if(y.cnt==0){
		ans=x;
	}
	else{
		ll tmp=(x.hashval*power[y.cnt]+y.hashval)%MOD;
		ans.hashval=tmp;
		ans.cnt=x.cnt+y.cnt;
	}
	
	return ans;
}

int main()
{
	//what the hell are youing? Think again before coding.
	//FastIO();
	power[0]=1;
	for(int i=1;i<maxn;i++){
		power[i]=(power[i-1]*base)%MOD;
	}
	
	scanf("%s",str);
	len=strlen(str);
	for(int i=0,j=len-1;i<len;i++,j--){
		str1[i]=str[j];
	}
	build();
	
	//cout<<t[1].hashval<<" "<<t[1].cnt<<" "<<t1[1].hashval<<" "<<t1[1].cnt<<endl;
	
	int q,i,l,r;
	char ch;
	scanf("%d",&q);
	char x[2];
	while(q--){
		scanf("%s",x);
		if(x[0]=='C'){
			scanf("%d %d",&l,&r);
			int a=l,b=r;
			l=getpos(l);
			r=getpos(r);
			node cur=query(1,1,len,l,r);
			
			//cout<<l<<" "<<r<<" "<<cur.hashval<<" "<<cur.cnt<<endl;
			
			l=len-b+1; r=len-a+1;
			
			int l1,r1;
			l1=len-l+1;
			r1=len-r+1;
			//cout<<l<<" "<<r<<" "<<l1<<" "<<r1<<endl;
			l=getpos1(l1);
			r=getpos1(r1);
			node next=query1(1,1,len,l,r);
			
			//cout<<l<<" "<<r<<" "<<next.hashval<<" "<<next.cnt<<endl;
			
			if(cur.hashval==next.hashval){
				printf("Yes!\n");
			}
			else{
				printf("No!\n");
			}
		}
		else if(x[0]=='D'){ //cout<<"OK"<<endl;
			scanf("%d",&i);
			int j=len-i+1;
			int j1=len-j+1;
			i=getpos(i);
			//cout<<"de "<<i<<endl;
			update(1,1,len,i,'*');
			i=getpos1(j1);
			//cout<<"de "<<i<<endl;
			update1(1,1,len,i,'*');
		}
		else{ //cout<<"OK"<<endl;
			scanf("%d %c",&i,&ch);
			int j=len-i+1;
			int j1=len-j+1;
			i=getpos(i);
			update(1,1,len,i,ch);
			i=getpos1(j1);
			update1(1,1,len,i,ch);
		}
	}

    return 0;
    //you should actually read the stuff at the bottom
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smooth instead of nothing and stay organized
	* don't get stuck on one approach, try another
	* don't waste time in one problem, try another
	* check PI value acos(-1.0)
*/