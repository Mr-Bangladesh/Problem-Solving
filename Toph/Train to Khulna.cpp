/**In the name of Allah, the Most Merciful, the Most Merciful.**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define INF 9223372036854775806
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define PI 2*acos(0.0)
#define EPS 1e-9
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; //order_of_key,find_by_order
ll mod(ll B,ll M){ll X=B%M; if(X>=0) return X; else return M+X;}
ll max(ll a,ll b) {if(a>b) return a; else return b;} ll min(ll a,ll b) {if(a<b) return a; else return b;}
ll fx4[]={1,-1,0,0}; ll fy4[]={0,0,1,-1};
map<char,int> id;
int main()
{
    id['J']=1; id['B']=2; id['A']=3; id['C']=4; id['K']=5; id['Q']=6; id['X']=7; id['Y']=8;

    map<int,int> val;

    val[1]=3; val[2]=2; val[3]=1; val[4]=1; val[5]=val[6]=val[7]=val[8]=0;

    int a[5];
    int b[5];
    char c;

    bool k=false,q=false;
    int x=0,y=0;
    for(int i=1;i<=4;i++){
        cin>>c;
        if(c=='K') k=true;
        if(c=='Q') q=true;
        a[i]=id[c];
    }
    if(k && q){
        y-=3;
    }
    k=false;
    q=false;
    for(int i=1;i<=4;i++){
        cin>>c;
        if(c=='K') k=true;
        if(c=='Q') q=true;
        b[i]=id[c];
    }
    if(k && q){
        x-=3;
    }
    sort(a+1,a+5);
    sort(b+1,b+5);

    //for(int i=1;i<=4;i++) cout<<a[i]<<" "; cout<<endl;
    //for(int i=1;i<=4;i++) cout<<b[i]<<" "; cout<<endl;

    //cout<<x<<" "<<y<<endl;
    int i=1,j=1;
    while(i<=4 && j<=4){
        if(k && q && (a[i]==5 || a[i]==6)){
            i++; continue;
        }
        if(k && q && (b[j]==5 || b[j]==6)){
            j++; continue;
        }
        if(a[i]<b[i]){
            x+=val[a[i]];
        }
        else{
            y+=val[b[i]];
        }
        i++;
        j++;
    }

    //cout<<x<<" "<<y<<endl;
    if(x>y){
        cout<<"Towfique Bhai, The DP_Master!"<<endl;
    }
    else if(y>x){
        cout<<"Nihad Bhai, The_Mathematician!"<<endl;
    }
    else{
        cout<<"Oh! It is a draw"<<endl;
    }

    return 0;
}


