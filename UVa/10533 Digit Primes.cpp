//#include <bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//#define MAX 1000005
//vector <ll> primes;
//ll prime[MAX];
//bool A[MAX+100];
//
//void sieve()
//{
//    primes.push_back(2);
//    prime[2]=1;
//
//    for(ll i=2;i<=MAX;i+=2)
//        A[i]=1;
//    for(ll i=3;i<=MAX;i++)
//    {
//        if(A[i]==0)
//        {
//            primes.push_back(i);
//            prime[i]=1;
//            for(ll j=i*i;j<=MAX;j+=i*2)
//                A[j]=1;
//        }
//    }
//
//}
//
//
//ll result[MAX];
//void digitprime()
//{
//    ll len=primes.size();
//    for(ll i=0;i<len;i++)
//    {
//        ll sum=0;
//        ll N=primes[i];
//        //cout<<"N "<<N<<endl;
//        while(N!=0)
//        {
//            sum+=(N%10);
//            N=N/10;
//        }
//        //cout<<"sum "<<sum<<endl;
//        if(prime[sum]==1) result[primes[i]]=1;
//    }
//}
//
//int main()
//{
//    sieve();
//    digitprime();
//    ll a,b;
//    ll N;
//    scanf("%lld",&N);
//    for(ll i=1;i<=N;i++)
//    {
//        scanf("%lld %lld",&a,&b);
//        if(a>b) swap(a,b);
//
//        ll Count=0;
//
//        for(ll j=a;j<=b;j++)
//        {
//            if(result[j]==1) Count++;
//        }
//
//        printf("%lld\n",Count);
//
//    }
//    return 0;
//}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 1000005
vector <ll> primes;
ll prime[MAX];
int A[MAX+100];

void sieve()
{
    primes.push_back(2);
    prime[2]=1;

    for(ll i=2;i<=MAX;i+=2)
        A[i]=1;
    for(ll i=3;i<=MAX;i+=2)
    {
        if(A[i]==0)
        {
            primes.push_back(i);
            prime[i]=1;
            for(ll j=i*i;j<=MAX;j+=i*2)
                A[j]=1;
        }
    }

}


ll result[MAX];
void digitprime()
{
    ll len=primes.size();
    ll Count=0;
    for(ll i=0;i<len;i++)
    {
        ll sum=0;
        ll N=primes[i];
        //cout<<"N "<<N<<endl;
        while(N!=0)
        {
            sum+=(N%10);
            N=N/10;
        }
        if(prime[sum]==1) Count++;

        result[primes[i]]=Count;
    }
}

int main()
{
    sieve();
    digitprime();
    ll S=0;
    for(ll i=2;i<=MAX;i++)
    {
        S=max(result[i],S);
        if(result[i]==0) result[i]=S;
    }

    ll a,b;
    ll N;
    //for(int i=2;i<=25;i++) cout<<result[i]<<endl;
    scanf("%lld",&N);
    for(ll i=1;i<=N;i++)
    {
        scanf("%lld %lld",&a,&b);
        //if(a==b){printf("%lld\n",result[b]); continue;}
        ll A=max(a,b);
        ll B=min(a,b);
        ll sum=result[A]-result[B-1];
        printf("%lld\n",sum);
    }
    return 0;
}

