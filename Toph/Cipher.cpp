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

void leftrotate(int arr[], int k, int n)
{
    int mod = k % n;
    int temp[n];
    for(int i=0;i<n;i++) temp[i]=arr[i];
    for (int i = 0; i < n; i++)
        arr[i]=(temp[(mod + i) % n]);
}

void reverseArray(int arr[], int start, int end)
{
    while (start < end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}
void rightrotate(int arr[], int d, int n)
{
    d=d%n;
    reverseArray(arr, 0, n-1);
    reverseArray(arr, 0, d-1);
    reverseArray(arr, d, n-1);
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        string s;
        cin>>s;
        int len=s.length();
        for(int i=len;i<n*m;i++) s+='0';
        int a[n][m];
        memset(a,0,sizeof(a));
        int r=0;
        for(int i=0;i<n*m;i+=m){
            for(int j=i;j<i+m;j++){
                a[r][j-i]=s[j]-64;
                if(s[j]=='0'){
                    a[r][j-i]=0;
                }
            }
            r++;
        }
        char c;
        int d;
        int temp[n];
        for(int i=0;i<m;i++){
            cin>>c>>d;
            if(c=='U'){
                for(int j=0;j<n;j++){
                    temp[j]=a[j][i];
                }
                leftrotate(temp,d,n);
                for(int j=0;j<n;j++){
                    a[j][i]=temp[j];
                }
            }
            else{
                for(int j=0;j<n;j++){
                    temp[j]=a[j][i];
                }
                rightrotate(temp,d,n);
                for(int j=0;j<n;j++){
                    a[j][i]=temp[j];
                }
            }
        }

        string ans="";
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j]==0){
                    ans+=" ";
                }
                else{
                    ans+=(a[i][j]+64);
                }
            }
        }
        len=ans.length();
//        for(int i=0;i<len;i++){
//            cout<<i<<" "<<int(ans[i])<<endl;
//        }
        string res="";
        int idx;
        for(int i=len-1;i>=0;i--){
            if(ans[i]!=32){
                idx=i; break;
            }
        }
        //cout<<idx<<endl;
        for(int i=0;i<=idx;i++) res+=ans[i];
        //cout<<ans<<" "<<res.length()<<endl;
        cout<<res<<endl;
    }

    return 0;
}


