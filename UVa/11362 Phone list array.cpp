#include <bits/stdc++.h>
using namespace std;
#define MAX_NODE 200005
int root,idx,trie[MAX_NODE][30],endpoint[MAX_NODE];
void init(){
    root=idx=0;
    for(int i=0;i<10;i++){
        trie[root][i]=-1;
    }
}
bool check=true;
void add(string s,int n){
    int now=root;
    int cnt=0;
    for(int i=0;i<n;i++){
        if(trie[now][s[i]-'0']==-1){
            trie[now][s[i]-'0']=++idx;
            cnt++;
            //cout<<"added "<<s[i]<<" "<<trie[now][s[i]-'0']<<endl;
            for(int j=0;j<10;j++){
                trie[idx][j]=-1;
            }
        }
        now=trie[now][s[i]-'0'];
    }
    //cout<<s<<" "<<n<<" "<<cnt<<endl;
    if(cnt==0){
            //cout<<cnt<<endl;
        check=false;
    }
    endpoint[now]=1;
}
bool cmp(string a,string b){
    return a.length()>b.length();
}
int main(){
    int t;
    //freopen("output.txt","w",stdout);
    cin>>t;
    int n;
    while(t--){
        cin>>n;

        string s;vector<string> v;
        for(int i=1;i<=n;i++){
            cin>>s;
            v.push_back(s);
        }
        sort(v.begin(),v.end(),cmp);
        bool ans=true;

        init();

        for(string s:v){
            add(s,s.length());
            if(!check){
                    //cout<<s<<endl;
                ans=false; break;
            }
        }
        if(ans) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

        memset(trie,-1,sizeof(trie));
        memset(endpoint,0,sizeof(endpoint));
        check=true;
    }
}
