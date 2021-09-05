#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

bool sortbysecond(const pair<int,int>&a, const pair<int,int>&b)
{
    return (a.second < b.second);
}

int main()
{

    LL T,n,k,p;
    cin>>T;
    for(LL i=1;i<=T;i++)
    {
        cin>>n;
        LL len=0;

        vector < pair<int,int> > S;
        vector < pair<int,int> > ::iterator it;

        for(LL j=0;j<n;j++)
        {
            cin>>k>>p;
            S.push_back(make_pair(k,p));
            len+=k;
        }

        sort(S.begin(),S.end(),sortbysecond);

        LL maximum=0;
        LL sum;

        for(it=S.begin();it!=S.end();it++)
        {
            sum=len*(it->second);
            //cout<<sum<<endl;
            len=len-(it->first);
            if(sum>=maximum)
                maximum=sum;
        }
        //cout<<maximum<<endl;
        printf("Case %lld: %lld\n",i,maximum);

    }
    return 0;
}





/*#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int main()
{

    LL T,n,k,p;
    //cin>>T;
    scanf("%lld",&T);
    for(LL i=1;i<=T;i++)
    {
        //cin>>n;
        scanf("%lld",&n);

        vector <LL> A;

        for(LL j=1;j<=n;j++)
        {
            //cin>>k>>p;
            scanf("%lld%lld",&k,&p);
            for(LL n=0;n<k;n++)
                A.push_back(p);
        }
        sort(A.begin(),A.end());

        LL len=A.size();

        LL arraysize=len;

        LL sum;

        LL maximum=0;

        for(LL j=0;j<arraysize;j++)
        {
            sum=A[j]*len;
            cout<<sum<<" ";
            if(sum>maximum)
                maximum=sum;
            len--;
        }

        printf("Case %lld: %lld\n",i,maximum);
    }
    return 0;
}*/
