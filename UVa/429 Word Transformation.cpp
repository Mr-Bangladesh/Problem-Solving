#include <bits/stdc++.h>
using namespace std;
int str(string A,string B)
{
    int L1=A.length();
    int L2=B.length();

    if(L1!=L2) return 0;

    int Count=0;
    for(int i=0;i<L1;i++)
    {
        if(A[i]!=B[i]) Count++;
    }

    if(Count==1) return 1;
    else return 0;
}

vector<int> graph[1000];
map<string,int> G1;
map<int,string> G2;
int level[10000];

void BFS(int source)
{
    int visited[10000]={0};
    queue<int> Q;
    visited[source]=1;
    Q.push(source);

    level[source]=0;

    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        for(int i=0;i<graph[u].size();i++)
        {
            int v=graph[u][i];

            if(visited[v]==0)
            {
                visited[v]=1;
                Q.push(v);
                level[v]=level[u]+1;
                //cout<<"visited "<<v<<" "<<G2[v]<<endl;
            }

        }
    }

}

int main()
{

    //freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);

    int testcase;
    cin>>testcase;
    for(int i=1;i<=testcase;i++)
    {
        string S[10000];
        int j=0;
        string S1;

        while(cin>>S1)
        {
            if(S1=="*") break;
            G1[S1]=j;
            G2[j]=S1;
            S[j++]=S1;
        }

        for(int k=0;k<j;k++)
        {
            for(int l=k+1;l<j;l++)
            {
                if(str(S[k],S[l])==1)
                {
                    graph[k].push_back(l);
                    graph[l].push_back(k);
                }
            }
        }


        string input;
        getchar();

        while(getline(cin,input))
        {
            if(input=="" "") break;
            //if(!getline(cin,input)) break;

            string source,destination;
            int pos=0;
            for(int j=0;j<input.length();j++)
            {
                if(input[j]==' '){pos=j; break;}
                source+=input[j];
            }
            for(int j=pos+1;j<input.length();j++) destination+=input[j];

            //cout<<source<<" "<<destination<<endl;

            BFS(G1[source]);
            int ans=level[G1[destination]];

            cout<<source<<" "<<destination<<" "<<ans<<endl;
            memset(level,0,sizeof(level));
        }

        G1.clear();
        G2.clear();
        for(int x=0;x<1000;x++) graph[x].clear();

        if(i%2==1) cout<<endl;

    }
    return 0;
}
