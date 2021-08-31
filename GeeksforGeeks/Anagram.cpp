#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	//code
	int T;
	cin>>T;
	while(T--){
	   string s,t;
	   cin>>s>>t;
	   int l1=s.length();
	   int l2=t.length();
	   if(l1!=l2){
	       cout<<"NO"<<endl; continue;
	   }
	   int cnt1[100]={0},cnt2[100]={0};

	   for(int i=0;i<l1;i++){
            cnt1[s[i]-95]++;
            //cout<<s[i]<<" "<<cnt1[s[i]-95]<<endl;
	   }

	   for(int i=0;i<l2;i++){
            cnt2[t[i]-95]++;
            //cout<<t[i]<<" "<<cnt2[t[i]]<<endl;
	   }

	   bool check=true;
	   for(int i=0;i<l1;i++){
	       if(cnt1[t[i]-95]!=cnt2[t[i]-95]){
                //cout<<t[i]<<" "<<cnt1[t[i]]<<" "<<cnt2[t[i]]<<endl;
	           cout<<"NO"<<endl; check=false; break;
	       }
	   }
	   if(check) cout<<"YES"<<endl;
	}
	return 0;
}
