#include <bits/stdc++.h>
#define ll long long int
using namespace std;
string s;
string K = "KEK";
ll dp[2001][4];
ll findans(ll start,ll temp){
	
	if(temp==3)
		return 1;
	
	if(s[start]=='\0')
		return 0;
	
	if(dp[start][temp]!=-1)
		return dp[start][temp];

	ll ans = findans(start+1,temp);
	if(s[start]==K[temp]){
		ans+=findans(start+1,temp+1);
	}
	return dp[start][temp] = ans;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll test;
    cin>>test;
    while(test--){
    	memset(dp,-1,sizeof(dp));
    	cin>>s;
    	ll ans = findans(0,0);
    	cout<< ans <<endl;
    }
    return 0;
}