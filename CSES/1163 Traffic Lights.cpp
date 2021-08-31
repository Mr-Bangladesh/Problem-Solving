/**In the name of Allah, the Most Merciful, the Most Merciful.**/
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
#define maxn 200005
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
///order_of_key,find_by_order
ll max(ll a,ll b) {if(a>b) return a; else return b;}
ll min(ll a,ll b) {if(a<b) return a; else return b;}

int main()
{
    int x,n;
    //cin>>x>>n;
    scanf("%d %d",&x,&n);
    int a;
    set<int> s;
    s.insert(0);
    s.insert(x);
    int cur=x;
    multiset<int> ms;
    ms.insert(x);
    for(int i=1;i<=n;i++){
        //cin>>a;
        scanf("%d",&a);
        s.insert(a);
        auto it=s.lower_bound(a); it--;
        auto it1=s.upper_bound(a);
        //cout<<*it<<" "<<*it1<<" "<<m[mp(*it,*it1)]<<endl;
        int l=a-(*it); int r=(*it1)-a;
        ms.insert(l);
        ms.insert(r);
        auto it2=ms.lower_bound(*it1-*it);
        ms.erase(it2);

        printf("%d ",(*ms.rbegin()));
    }
    printf("\n");

    return 0;
}


