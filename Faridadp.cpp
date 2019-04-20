#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll n,a[10001];
ll dp[10001];

ll find_ans(ll n)
{
	dp[0] = 0;
	dp[1] = a[0];
	for(ll i=2;i<=n;i++)
	{
		dp[i] = max(a[i-1] + dp[i-2],dp[i-1]);
	}
	return dp[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll test;
    cin>>test;
    for(ll j=1;j<=test;j++)
    {
    	cin>>n;
    	for(ll i=0;i<n;i++)
    		cin>>a[i];
    	memset(dp,-1,sizeof(dp));
    	ll ans = find_ans(n);
    	cout<<"Case "<<j<<": "<<ans<<endl;
    }
    return 0;
}