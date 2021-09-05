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

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        vector<int> neg,pos;
        for(int i=1;i<=n;i++){
            int x;
            scanf("%d",&x);
            if(x<0) neg.pb(x*(-1));
            else pos.pb(x);
        }
        sort(neg.begin(),neg.end());
        sort(pos.begin(),pos.end());

        int x=neg.size(),y=pos.size();
        if(x==0 || y==0){
            printf("1\n");
            continue;
        }
        int l=1,r=0;
        int last=neg[0],idx=-1;
        int cnt=1;
        while(l<=x && r<=y){
            if(idx==-1){
                if(r<y && pos[r]>last){
                    last=pos[r];
                    idx=1;
                    r++;
                    cnt++;
                }
                else r++;
            }
            else{
                if(l<x && neg[l]>last){
                    last=neg[l];
                    idx=-1;
                    l++;
                    cnt++;
                }
                else l++;
            }
        }
        int ans=cnt;

        l=0;r=1;
        last=pos[0];idx=1;
        cnt=1;
        while(l<=x && r<=y){
            if(idx==-1){
                if(r<y && pos[r]>last){
                    last=pos[r];
                    idx=1;
                    r++;
                    cnt++;
                }
                else r++;
            }
            else{
                if(l<x && neg[l]>last){
                    last=neg[l];
                    idx=-1;
                    l++;
                    cnt++;
                }
                else l++;
            }
        }

        ans=max(ans,cnt);
        printf("%d\n",ans);
    }

    return 0;
}

