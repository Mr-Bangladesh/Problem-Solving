#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 9223372036854775806
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define PI 2*acos(0.0)
ll mod(ll B,ll M){ll X=B%M; if(X>=0) return X; else return M+X;}
///cin.ignore();
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}
ll fx4[]={1,-1,0,0}; ll fy4[]={0,0,1,-1};

char zero[5][5],one[5][5],two[5][5],three[5][5],four[5][5],five[5][5],six[5][5],seven[5][5],eight[5][5],nine[5][5];

void F(ll n){
        if(n==0){
            for(int i=0;i<5;i++){
                for(int j=0;j<3;j++) cout<<zero[i][j]; cout<<endl;
            }
        }
        else if(n==1){
            for(int i=0;i<5;i++) cout<<one[i][0]<<endl;
        }
        else if(n==2){
            for(int i=0;i<5;i++){
                for(int j=0;j<3;j++) cout<<two[i][j]; cout<<endl;
            }
        }
        else if(n==3){
            for(int i=0;i<5;i++){
                for(int j=0;j<3;j++) cout<<three[i][j]; cout<<endl;
            }
        }
        else if(n==4){
            for(int i=0;i<5;i++){
                for(int j=0;j<3;j++) cout<<four[i][j]; cout<<endl;
            }
        }
        else if(n==5){
            for(int i=0;i<5;i++){
                for(int j=0;j<3;j++) cout<<five[i][j]; cout<<endl;
            }
        }
        else if(n==6){
            for(int i=0;i<5;i++){
                for(int j=0;j<3;j++) cout<<six[i][j]; cout<<endl;
            }
        }
        else if(n==7){
            for(int i=0;i<5;i++){
                for(int j=0;j<3;j++) cout<<seven[i][j]; cout<<endl;
            }
        }
        else if(n==8){
            for(int i=0;i<5;i++){
                for(int j=0;j<3;j++) cout<<eight[i][j]; cout<<endl;
            }
        }
        else{
            for(int i=0;i<5;i++){
                for(int j=0;j<3;j++) cout<<nine[i][j]; cout<<endl;
            }
        }

    }
int main()
{
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/input.txt","r",stdin);
    //freopen("C:/Users/Md Faizul Haque/Desktop/Solving/output.txt","w",stdout);

    ll t,n,m,x,y,w,k,q,r,p,cs;

    for(int i=0;i<5;i++){
        for(int j=0;j<3;j++){
            one[i][j]=two[i][j]=three[i][j]=four[i][j]=five[i][j]=six[i][j]=seven[i][j]=eight[i][j]=nine[i][j]=' ';
        }
    }

    for(int i=0;i<5;i++) one[i][0]='*';

    for(int i=0;i<3;i++){
        zero[0][i]=two[0][i]=three[0][i]=five[0][i]=six[0][i]=seven[0][i]=eight[0][i]=nine[0][i]='*';
    }

    for(int i=0;i<5;i++){
        zero[i][0]=six[i][0]=eight[i][0]='*';
    }

    for(int i=0;i<5;i++){
        zero[i][2]=three[i][2]=four[i][2]=seven[i][2]=eight[i][2]=nine[i][2]='*';
    }

    for(int i=0;i<3;i++){
        zero[4][i]=two[4][i]=three[4][i]=five[4][i]=six[4][i]=eight[4][i]='*';
    }

    for(int i=0;i<3;i++){
        two[2][i]=three[2][i]=four[2][i]=five[2][i]=six[2][i]=eight[2][i]=nine[2][i]='*';
    }

    for(int i=0;i<3;i++){
        two[i][2]='*';
    }
    for(int i=2;i<5;i++){
        two[i][0]='*';
    }

    for(int i=0;i<3;i++){
        four[i][0]=five[i][0]=nine[i][0]='*';
    }

    for(int i=2;i<5;i++){
        five[i][2]=six[i][2]='*';
    }

    cin>>t;

    for(cs=1;cs<=t;cs++){
        char ch;
        ll a,b;
        cin>>a>>ch>>b;
        ll ans;
        if(ch=='+') ans=a+b;
        else if(ch=='-') ans=a-b;
        else ans=a*b;

        vector<ll> v;

        ll ss=0; if(ans<0){
            ss=1;
            ans=ans*(-1);
        }
        //cout<<ans<<endl;
        while(ans!=0){
            v.pb(ans%10);
            ans/=10;
        }
        reverse(v.begin(),v.end());
        cout<<"Case #"<<cs<<":"<<endl;
        for(x:v){
            //cout<<x<<endl;
            F(x);
        }
        cout<<endl;

    }


    return 0;
}



