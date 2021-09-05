#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    string s;
    cin>>s;
    int cnt[27]={0};
    for(int i=0;i<n;i++){
        cnt[s[i]-96]++;
    }
    int a[27]={0};
    int uni=0,j=1;
    for(int i=1;i<=26;i++){
        if(cnt[i]){
            uni++;
            a[j]=cnt[i];
            j++;
        }
    }
    if(uni==k){
        printf("0\n"); return 0;
    }
    if(uni<k){
        printf("%d\n",k-uni);
        return 0;
    }
    sort(a+1,a+j);
    int ans=0;
    for(int i=1;i<=uni-k;i++){
        ans+=a[i];
    }
    printf("%d\n",ans);
    return 0;

}
