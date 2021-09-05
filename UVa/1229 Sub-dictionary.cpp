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
map<string, set<string> > g,gr;
map<string,int> mark;
stack<string> st;

void dfs1(string u){
    mark[u]=1;
    for(string v:g[u]){
        if(!mark[v]){
            dfs1(v);
        }
    }
    st.push(u);
}

map<string,int> mark1;
map<int,set<string> > comp;

void dfs2(string u,int idx){
    mark1[u]=1;
    comp[idx].insert(u);
    for(string v:gr[u]){
        if(!mark1[v]){
            dfs2(v,idx);
        }
    }
}

int main()
{
    int n;
    while(scanf("%d",&n),n){
        getchar();
        set<string> node;
        for(int i=1;i<=n;i++){
            string s;
            getline(cin,s);
            istringstream input(s);
            string a,b;
            input>>b;
            node.insert(b);
            while(input>>a){
                g[b].insert(a);
                gr[a].insert(b);
                node.insert(a);
            }
        }
        for(auto s:node){
            if(!mark[s]){
                dfs1(s);
            }
        }
        int idx=0;
        while(!st.empty()){
            string u=st.top(); st.pop();
            if(!mark1[u]){
                dfs2(u,++idx);
            }
        }
        int x=1,mx=0;
        for(int i=1;i<=idx;i++){
            if(comp[i].size()>mx){
                mx=comp[i].size();
                x=i;
            }
        }

        printf("%d\n",mx);
        for(string s:comp[x]){
            cout<<s<<" ";
        }
        printf("\n");

        g.clear(); gr.clear(); mark.clear(); mark1.clear(); comp.clear();
    }

    return 0;
}

