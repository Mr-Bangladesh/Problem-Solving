#include <iostream>
#include <string>
using namespace std;
bool ok(string S,int x){
    for(int i=1;i<x;i++) if(S[i]==S[i-1]) return false;
    return true;
}
string F(string S,int len){
    if(len<=0) return S;
    if(len>0){
        int i=len-1;
        while(S[i]==S[len] && i>=0){
            S[i]='1';
            i--;
        }
        if(i!=len-1){
            S[len]='1';
            //r(i+1,x-1,len-i);
            //cout<<S<<" "<<i<<" "<<len<<endl;
            return F(S,i);
        }
        else return F(S,len-1);
    }
}
int main(){
    int T;
    cin>>T;
    while(T--){
        string S;
        cin>>S;
        while(1){
            int len=S.length();
            if(ok(S,len)) break;
            S=F(S,len-1);
            //cout<<ans<<endl;
            string ans;
            for(int i=0;i<len;i++) if(S[i]!='1') ans+=S[i];
            S=ans;
        }
        cout<<S<<endl;
    }
}
