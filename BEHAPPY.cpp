#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll m,n;
ll A[21],B[21];
ll dp[21][101];
ll f(ll gf,ll gifts)
{
	if(gf==m-1){
		if(gifts>=A[gf] && gifts<=B[gf])
			return 1;
		else
			 return 0;
	}
	if(gifts<A[gf])
		return 0;
	if(dp[gf][gifts]!=-1)
		return dp[gf][gifts];
	ll ans = 0;
	for(ll i = A[gf];i<=min(B[gf],gifts);i++)
	{
		ans+=f(gf+1,gifts-i);
	}
	return dp[gf][gifts] = ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(true){
    	cin>>m>>n;
    	if(m==0 && n==0)
    		return 0;
    	memset(dp,-1,sizeof(dp));
    	for(ll i=0;i<m;i++)
    		cin>>A[i]>>B[i];
    	ll ans = f(0,n);
    	cout<< ans <<endl;
    }
    return 0;
}