#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
int main(){
    ll t,n,q;
    scanf("%lld",&t);
    for(ll cs=1;cs<=t;cs++){
        scanf("%lld %lld",&n,&q);
        ll a[n+4];
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
        }
        ll st[n+5];
        st[1]=1;
        for(int i=2;i<=n;i++){
            if(a[i]==a[i-1]){
                st[i]=st[i-1];
            }
            else{
                st[i]=i;
            }
        }
        ll cnt[n+4]={0};
        cnt[1]=1;
        for(int i=2;i<=n;i++){
            if(a[i]==a[i-1]){
                cnt[i]=cnt[i-1];
            }
            else{
                cnt[i]=cnt[i-1]+1;
            }
        }
        printf("Case %lld:\n",cs);
        while(q--){
            ll i,j;
            scanf("%lld %lld",&i,&j);
            printf("%lld\n",cnt[j]-cnt[st[i]-1]);
        }
    }
}
