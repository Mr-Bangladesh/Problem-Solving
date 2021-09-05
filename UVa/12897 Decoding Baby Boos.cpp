#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 100000000000000000
#define pb push_back
#define mp make_pair
///cin.ignore();
ll max(ll a,ll b) {if(a>b) return a; else return b;}
ll min(ll a,ll b) {if(a<b) return a; else return b;}
ll pow(ll B,ll P) { ll S=1; for(ll i=1;i<=P;i++) S=S*B; return S;}
int fx4[]={1,-1,0,0}; int fy4[]={0,0,1,-1};

int main()
{
    int T,N;

    cin>>T;

    for(int C=1;C<=T;C++)
    {
        string S;
        cin>>S;

        int len=S.length();

        cin>>N;

        char X,Y; map<char,char> Parent;

        for(int i=0;i<len;i++) Parent[S[i]]=S[i];

        for(int i=1;i<=N;i++)
        {
            cin>>X>>Y;
            Parent[Y]=X;
        }

        string ans;

        for(int i=0;i<len;i++)
        {
            if(S[i]=='_') ans+='_';
            else ans+=(Parent[S[i]]);
        }

        cout<<ans<<endl;
    }

    return 0;
}
