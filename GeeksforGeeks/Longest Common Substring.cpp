#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
	//code
	int T,N,M;
	cin>>T;
	while(T--){
	    cin>>N>>M;
	    string s,t;
	    cin>>s>>t;
	    int cnt[N+2][M+2];
	    memset(cnt,0,sizeof(cnt));
	    int ans=0;
	    for(int i=0;i<N;i++){
	        for(int j=0;j<M;j++){
	            if(s[i]==t[j]){
	                if(i>0 && j>0) cnt[i][j]=cnt[i-1][j-1]+1;
	                else cnt[i][j]=1;
	                ans=max(ans,cnt[i][j]);
	            }
	        }
	    }
	    memset(cnt,0,sizeof(cnt));
	    cout<<ans<<endl;
	}
	return 0;
}
