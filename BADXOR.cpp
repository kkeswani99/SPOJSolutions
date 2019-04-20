#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll mod = 100000007;
ll dp[1025][1025];
ll n,m;
ll a[1001];

void init_dp()
{
	dp[0][0] = 1;
	for(ll i=1;i<=n;i++){
		for(ll j=0;j<1025;j++){
			dp[i][j] = (dp[i-1][j] + dp[i-1][j^a[i-1]])%mod;
		}
	}
	return ;
}
ll p(ll n)
{
	if(n==1)
		return 2;
	if(n==0)
		return 1;
	ll temp = p(n/2);
	temp = (temp*temp)%mod;
	if(n&1)
		temp = (temp*2)%mod;
	return temp;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll test;
    cin>>test;
    for(ll t = 1;t<=test;t++){
    	memset(dp,0,sizeof(dp));
    	cin>>n>>m;
    	for(ll i=0;i<n;i++)
    		cin>>a[i];
    	init_dp();
    	ll ans = 0;
    	for(ll j=0;j<m;j++){
    		ll temp;
    		cin>>temp;
    		ans = (ans + dp[n][temp])%mod;
    	}
    	ll f_ans = p(n)%mod;
    	f_ans = (f_ans - ans + mod)%mod;
    	cout<<"Case "<<t<<": "<<f_ans<<endl;
    }
    return 0;
}