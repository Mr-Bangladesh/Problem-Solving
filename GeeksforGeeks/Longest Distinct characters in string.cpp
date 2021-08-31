#include <iostream>
#include <string>
using namespace std;

int main() {
	//code
	int T;
	cin>>T;
	while(T--){
	    string S;
	    cin>>S;
	    int len=S.length();
	    int mark[257];
	    for(int i=0;i<257;i++) mark[i]=-1;
	    int cnt=1,ans=1;
	    mark[S[0]]=0;
        int minidx=0;
	    for(int i=1;i<len;i++){
            int idx=mark[S[i]];
            if(idx!=-1){
                    //cout<<i<<" "<<minidx<<endl;
                ans=max(ans,i-minidx);
                minidx=max(minidx,mark[S[i]]+1);
            }
            mark[S[i]]=i;
	    }
	    ans=max(ans,len-minidx);
	    cout<<ans<<endl;
	}
	return 0;
}

