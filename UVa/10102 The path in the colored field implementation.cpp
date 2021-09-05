///***Bismillahir Rahmanir Rahim***

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 100000000000000000
#define pb push_back
#define mp make_pair
///cin.ignore();
void FastIO() {ios_base:: sync_with_stdio(false); cin.tie(0); cout.precision(20);}
ll max(ll a,ll b) {if(a>b) return a; else return b;}
ll min(ll a,ll b) {if(a<b) return a; else return b;}
ll pow(ll B,ll P) { ll S=1; for(ll i=1;i<=P;i++) S=S*B; return S;}
int fx4[]={1,-1,0,0}; int fy4[]={0,0,1,-1};


///***Faizul***CSE**4th batch**BU


int main()
{
    FastIO();

    //freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);

    int M;

    while(cin>>M)
    {
        string S[1000];

        vector < pair<int,int> > V1;

        vector < pair<int,int> > V2;

        for(int i=0;i<M;i++)
        {
            cin>>S[i];
            for(int j=0;j<M;j++)
            {
                if(S[i][j]=='1')
                    V1.pb(mp(i,j));
                else if(S[i][j]=='3')
                    V2.pb(mp(i,j));
            }
        }

        int dist=INT_MAX,X=0;

        int ans=0;

        for(int i=0;i<V1.size();i++)
        {
            int u1=V1[i].first;
            int u2=V1[i].second;

            dist=INT_MAX;

            for(int j=0;j<V2.size();j++)
            {
                int v1=V2[j].first;
                int v2=V2[j].second;

                X=abs(u1-v1) + abs(u2-v2);
                dist=min(dist,X);
            }
            //cout<<dist<<endl;
            ans=max(ans,dist);
        }

        cout<<ans<<endl;

    }

    return 0;
}
