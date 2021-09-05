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
    int N,A[200005]={0};

    //freopen("1.txt","r",stdin);

    while(scanf("%d",&N)!=EOF)
    {
        if(N==-999999) break;
        int j=1;
        A[j]=N;
        j++;
        while(scanf("%d",&N))
        {
            if(N==-999999) break;
            A[j]=N;
            j++;
        }

        ll sum=1,ans=INT_MIN;

        for(int i=1;i<j;i++)
        {
            sum=1;
            ll temp=INT_MIN;
            for(int k=i;k<j;k++)
            {
                sum=sum*A[k];
                temp=max(temp,sum);
            }
            ans=max(ans,temp);
        }

        if(ans==INT_MIN) break;

        cout<<ans<<endl;
    }

    return 0;
}
