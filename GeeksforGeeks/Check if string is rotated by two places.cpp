#include <iostream>
#include <string>
using namespace std;
string rr(string S){
    int len=S.length(); string a;
    for(int i=2;i<len;i++) a+=S[i];
    a+=S[0]; a+=S[1];
    return a;
}
string rr1(string S){
    int len=S.length();
    string a;
    a+=S[len-2]; a+=S[len-1];
    for(int i=0;i<len-2;i++) a+=S[i];
    return a;
}
int main() {
	int T;
	cin>>T;
	while(T--){
	    string a,b;
	    cin>>a>>b;
	    if(rr(b)==a){
	        cout<<1<<endl;
	    }
	    else if(rr1(b)==a){
	        cout<<1<<endl;
	    }
	    else{
	        cout<<0<<endl;
	    }
	}
	return 0;
}
