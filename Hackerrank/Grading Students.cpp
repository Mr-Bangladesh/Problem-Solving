#include <bits/stdc++.h>
using namespace std;
int main(){
    int N,X;
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>X;
        int d=X/5; int r=5*(d+1);
        if(r<40){
            cout<<X<<endl;
        }
        else if(r-X<3){
            cout<<r<<endl;
        }
        else cout<<X<<endl;
    }
    return 0;
}
