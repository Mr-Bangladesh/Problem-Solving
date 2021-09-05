/**In the name of Allah, the Most Merciful, the Most Merciful.**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define INF 9223372036854775806
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define PI 2*acos(0.0)
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; //order_of_key,find_by_order
ll mod(ll B,ll M){ll X=B%M; if(X>=0) return X; else return M+X;}
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}
ll fx4[]={1,-1,0,0}; ll fy4[]={0,0,1,-1};
bool cmp(pair<string,int> a,pair<string,int> b){
    if(a.second==b.second) return a.first<b.first;
    return a.second<b.second;
}
int main()
{
    freopen("1.txt","r",stdin);
    int t;
    scanf("%d",&t);
    //getchar();
    while(t--){
        string title; getchar();
        getline(cin,title); //cout<<title<<endl;
        int m,n,b;
        scanf("%d %d %d",&m,&n,&b);
        map<string,int> price;
        //getchar();
        for(int i=1;i<=m;i++){
            string s; int x;
            //getline(cin,s);
            cin>>s;
            scanf("%d",&x);
            price[s]=x;
            //cout<<"element "<<s<<" price "<<x<<endl;
        }
        int cnt=0;
        vector<pair<string,int> > ans;
        //getchar();
        for(int j=1;j<=n;j++){
            string recipe; getchar();
            getline(cin,recipe);
            int k;
            scanf("%d",&k); //cout<<recipe<<" elements "<<k<<" "<<j<<endl;
            //getchar();
            int cost=0;
            for(int i=1;i<=k;i++){
                string s; int x;
                //getline(cin,s);
                cin>>s;
                scanf("%d",&x); //cout<<s<<" quantity "<<x<<endl;
                cost+=(price[s]*x);
            }
            if(cost<=b){
                cnt++;
                ans.pb(mp(recipe,cost));
            }
        }
        sort(ans.begin(),ans.end(),cmp);
//        for(auto it:ans){
//            cout<<it.first<<" "<<it.second<<endl;
//        }
        transform(title.begin(),title.end(),title.begin(),::toupper);
        cout<<title<<endl;
        if(cnt==0){
            printf("Too expensive!\n");
        }
        else{
            for(auto it:ans) cout<<it.first<<endl;
        }
        printf("\n");
    }

    return 0;
}

