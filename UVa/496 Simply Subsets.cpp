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
#define EPS 1e-9
ll max(ll a,ll b) {if(a>b) return a; else return b;}
ll min(ll a,ll b) {if(a<b) return a; else return b;}

int main()
{
    string s;
    while(getline(cin,s)){
        stringstream input(s);
        string a;
        vector<int> v;
        while(input>>a){
            v.pb(stoi(a));
        }
        getline(cin,s);
        stringstream input1(s);
        vector<int> u;
        while(input1>>a){
            u.pb(stoi(a));
        }

        map<int,int> mark;
        for(int x:v){
            mark[x]=1;
        }

        if(u.size()==v.size()){
            int len=u.size();
            int cnt=0;
            for(int x:u){
                if(mark[x]){
                    cnt++;
                }
            }
            if(cnt==len){
                printf("A equals B\n");
            }
            else if(cnt>0){
                printf("I'm confused!\n");
            }
            else{
                printf("A and B are disjoint\n");
            }
        }
        else if(v.size()>u.size()){
            int len=u.size();
            int cnt=0;
            for(int x:u){
                if(mark[x]){
                    cnt++;
                }
            }
            if(cnt==len){
                printf("B is a proper subset of A\n");
            }
            else if(cnt>0){
                printf("I'm confused!\n");
            }
            else{
                printf("A and B are disjoint\n");
            }
        }
        else{
            int len=v.size();
            int cnt=0;
            for(int x:u){
                if(mark[x]){
                    cnt++;
                }
            }
            if(cnt==len){
                printf("A is a proper subset of B\n");
            }
            else if(cnt>0){
                printf("I'm confused!\n");
            }
            else{
                printf("A and B are disjoint\n");
            }
        }
    }

    return 0;
}


