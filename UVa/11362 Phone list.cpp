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
    node* next[26 + 1];
    node()
    {
        endmark = false;
        for (int i = 0; i < 26; i++)
            next[i] = NULL;
    }
} * root;

bool check=true;
void add(string s,int n){
    node* cur=root;
    int cnt=0;
    for(int i=0;i<n;i++){
        int id=s[i]-'0';
        if(cur->next[id]==NULL){
            cur->next[id]=new node();
            cnt++;
        }
        cur=cur->next[id];
    }
    //cout<<n<<" "<<cnt<<endl;
    cur->endmark=true;
    //cout<<"ok"<<endl;
    if(cnt==0){
        check=false;
    }
}
void del(node* cur)
{
    for (int i = 0; i < 26; i++)
        if (cur->next[i])
            del(cur->next[i]);

    delete (cur);
}
bool comp(string a,string b){
    return a.length()>b.length();
}
int main()
{
    //freopen("C:/Users/Faizul/OneDrive/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Faizul/OneDrive/Solving/output.txt","w",stdout);

    //freopen("output.txt","w",stdout);

    ll t,n,m,x,y,w,k,q,r,p,cs;

    scanf("%lld",&t);
    while(t--){
        scanf("%lld",&n);
        root =new node();
        string s;
        vector<string> v;
        for(int i=1;i<=n;i++){
            cin>>s;
            v.pb(s);
        }
        sort(v.begin(),v.end(),comp);
        //cout<<"ok"<<endl;
        bool ans=true;
        for(string s:v){
            add(s,s.length()); //cout<<"ok"<<endl;
            if(!check){
                ans=false; break;
            }
        }
        if(ans) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

        del(root);
        check=true;
    }

    return 0;
}
