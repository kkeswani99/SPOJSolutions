#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll mod = 10;
ll pow_mod(ll x,ll p)
{
	if(p==1)
		return x%mod;
	if(p==0)
		return 1%mod;
	ll ans = 1;
	if(p&1)
	{
		ans = (ans*x)%mod;
	}
	ll temp = pow_mod(x,p/2);
	temp = (temp*temp)%mod;
	ans = (ans*temp)%mod;
	return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll test;
    cin>>test;
    while(test--)
    {
    	ll a,b;
    	cin>>a>>b;
    	ll ans = pow_mod(a,b);
    	cout<< ans <<endl;
    }
    return 0;
}