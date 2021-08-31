/**In the name of Allah, the Most Merciful, the Most Merciful.**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define INF 9223372036854775806
#define pb push_back
#define mp make_pair
#define MAX_NODE 2000005

int root,idx,trie[MAX_NODE][2],endpoint[MAX_NODE];
void init(){
    root=idx=0;
    for(int i=0;i<2;i++){
        trie[root][i]=-1;
    }
}
void add(int n){
    int now=root;
    for (int i=30;i>=0;i--){
        int id=(n>>i)&1;
        if(trie[now][id]==-1){
            trie[now][id]=++idx;
            for(int j=0;j<2;j++){
                trie[idx][j]=-1;
            }
        }
        now=trie[now][id];
    }
    endpoint[now]=1;
}
int f(int n){
    int now=root;
    int ans=0;
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
    return ans;
}

int main()
{
    //freopen("C:/Users/Faizul/OneDrive/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Faizul/OneDrive/Solving/output.txt","w",stdout);

    ll t,n,m,x,y,w,k,q,r,p,cs;

    init();

    cin>>n;
    int a[n+2];
    for(int i=1;i<=n;i++){
        cin>>a[i];
        add(a[i]);
    }

    cin>>m;
    for(int i=1;i<=m;i++){
        cin>>x;
        cout<<f(x)<<endl;
    }


    return 0;
}


