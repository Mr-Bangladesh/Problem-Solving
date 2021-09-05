// Problem: Game of Palindromes
// Contest: Toph
// URL: https://toph.co/p/game-of-palindromes
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

/**In the name of Allah, the Most Merciful, the Most Merciful.**/
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable" 
#pragma GCC diagnostic ignored "-Wformat"
#include <bits/stdc++.h>
using namespace std;
int main()
{
	//what the hell are youing? Think again before coding.
	//FastIO();
	
	int t;
	cin>>t;
	while(t--){
		string s;
		int n;
		cin>>s;
		n=s.length();
		int tot=0,cnt=0;
		for(int i=0;i<n;i++){
			string a="",b="";
			for(int j=i;j<n;j++){
				a+=s[j];
				b=s[j]+b;
				//reverse(b.begin(),b.end());
				if(a==b){
					cnt++;
				}
				tot++;
			}
		}
		double ans=(double)cnt/(double)tot;
		printf("%.3f\n",ans);
	}

    return 0;
    //you should actually read the stuff at the bottom
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smooth instead of nothing and stay organized
	* don't get stuck on one approach, try another
	* don't waste time in one problem, try another
	* check PI value acos(-1.0)
*/