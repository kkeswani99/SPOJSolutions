#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll n;
ll a[202];
ll dp[202][202][202];
ll f(ll i,ll j,ll k)
{
	//Base Case
	if(k==n)
	{
		// Only one element is left
		if(a[k]>a[i])
			return 0;
		if(a[k]<a[j])
			return 0;
		return 1;
	}
	if(dp[i][j][k]!=-1)
		return dp[i][j][k];
	//Recursive Case
	// i denotes the number that has been painted black
	//k denotes index of element that i am currently on
	ll ans = INT_MAX;
	if(a[k]>a[i])
	{
		// I can include this element in black
		ans = min(ans,f(k,j,k+1));
	}
	if(a[k]<a[j])
	{
		ans = min(ans,f(i,k,k+1));
	}
	// Not Painting the element
	ans = min(ans,1 + f(i,j,k+1));
	return dp[i][j][k] = ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(true)
    {
    	cin>>n;
    	if(n==-1)
    		return 0;
    	memset(dp,-1,sizeof(dp));
    	for(ll i=1;i<=n;i++)
    		cin>>a[i];
    	a[n+1] = 1000001;
    	ll ans = f(0,n+1,1);
    	cout<< ans <<endl;
    }
    return 0;
}