#include <iostream>
using namespace std;

int main() {
	//code
	int T;
	cin>>T;
	cin.ignore();
	while(T--){
	    string a;
	    getline(cin,a);
	    //reverse(a.begin(),a.end());
	    int len=a.length();
	    bool mark[257]={0};
	    for(int i=0;i<len;i++){
	        if(!mark[a[i]]){
	            cout<<a[i];
	            mark[a[i]]=1;
	        }
	    }
	    cout<<endl;
	}
	return 0;
}
