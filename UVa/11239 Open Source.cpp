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
bool cmp(pair<string,int> a, pair<string,int> b){
    if(a.second==b.second) return a.first<b.first;
    return a.second>b.second;
}
int main()
{
    //freopen("1.txt","r",stdin);
    bool check=true;
    while(check){
        string s,id;
        map<string,string> mark;
        map<string,set<string> > cnt;
        set<string> projects;
        map<string,set<string> > lisst;
        string par="";
        while(getline(cin,s)){
            if(s[0]=='1'){
                break;
            }
            if(s[0]=='0'){
                check=false; break;
            }
            if(s[0]>='A' && s[0]<='Z'){
                par=s;
                projects.insert(par);
                continue;
            }
            lisst[par].insert(s);
            //cout<<"parent "<<par<<" "<<s<<endl;
        }
        if(!check) break;
        map<string,bool> akaimma;
        for(auto it:projects){
            //cout<<it<<"--> ";
            for(auto id:lisst[it]){
                if(akaimma[id]) continue;
                //cout<<id<<" ";
                if(mark[id]==""){
                    mark[id]=it;
                    cnt[it].insert(id); //cout<<"inserted "<<id<<" in "<<it<<endl;
                }
                else{
                    cnt[mark[id]].erase(id);
                    akaimma[id]=true; //cout<<"deleted "<<id<<" from "<<mark[id]<<endl;
                }
            }//cout<<endl;
        }
        vector< pair<string,int> > ans;
        for(auto it:projects){
            ans.pb(mp(it,cnt[it].size()));
        }
        sort(ans.begin(),ans.end(),cmp);
        for(auto it:ans){
            cout<<it.first<<" "<<it.second<<endl;
        }
    }

    return 0;
}

