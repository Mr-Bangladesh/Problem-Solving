/**In the name of Allah, the Most Merciful, the Most Merciful.**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define INF 9223372036854775806
#define pb push_back
#define mp make_pair
ll MOD=1000000007;
#define PI 2*acos(0.0)
ll mod(ll B,ll M){ll X=B%M; if(X>=0) return X; else return M+X;}
///cin.ignore();
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}
ll fx4[]={1,-1,0,0}; ll fy4[]={0,0,1,-1};
#define MAX_NODE 3000005
int root,idx,trie[MAX_NODE][3],endpoint[MAX_NODE];
void init(){
    root=idx=0;
    for(int i=0;i<2;i++){
        trie[root][i]=-1;
    }
}
unordered_map<int,int> index1;
void add(int n){
    int now=root;
    for(int i=30;i>=0;i--){
        int id=(n>>i)&1;
        //cout<<n<<" "<<i<<" "<<id<<" "<<now<<" "<<trie[now][id]<<endl;
        if(trie[now][id]==-1){
            trie[now][id]=++idx;
            //cout<<"added "<<n<<" "<<i<<" "<<id<<" "<<idx<<endl;
            trie[idx][0]=trie[idx][1]=-1;
        }
        now=trie[now][id];
    }
    endpoint[now]=1;
}
int ans=0;
void f(int n){
    int now=root;
    for(int i=30;i>=0;i--){
        int id=(n>>i)&1;
        if(trie[now][id^1]!=-1){
            ans|=(1<<i);
            now=trie[now][id^1];
        }
        else{
            now=trie[now][id];
        }
    }
}
int main()
{
    //freopen("C:/Users/Faizul/OneDrive/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Faizul/OneDrive/Solving/output.txt","w",stdout);

    int t,n,m,x,y,w,k,q,r,p,cs;

    scanf("%d",&n);
    ll a[n+1];
    init();
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        index1[a[i]]=i;
        add(a[i]);
    }
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        scanf("%d",&x);
        f(x);
        int num=ans^x;
        printf("Query %d: %d %d\n",i,index1[num],ans);
        ans=0;
    }

    return 0;
}

