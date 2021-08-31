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
struct node {
    bool endmark;
    node* next[2];
    node()
    {
        endmark = false;
        next[0]=NULL;
        next[1]=NULL;
    }
} * root;
void add(int n)
{
    node* curr = root;
    for (int i=31;i>=0;i--){
        int id=(n>>i)&1;
        if (curr->next[id] == NULL)
            curr->next[id] = new node();
        curr = curr->next[id];
    }
    curr->endmark = true;
}
int f(int n)
{
    node* curr = root;
    int ans=0;
    for (int i=31;i>=0;i--) {
        int id=((n>>i)&1);
        if(curr->next[id^1]!=NULL){
            ans|=(1<<i);
            //cout<<i<<" "<<ans<<endl;
            curr=curr->next[id^1];
        }
        else{
            curr=curr->next[id];
        }
    }
    //cout<<ans<<endl;
    return ans;
}
int main()
{
    //freopen("C:/Users/Faizul/OneDrive/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Faizul/OneDrive/Solving/output.txt","w",stdout);

    ll t,n,m,x,y,w,k,q,r,p,cs;

    root=new node();

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

