#include <bits/stdc++.h>
#define ll long long int
using namespace std;
vector<int> dp;
void maxProfitcalc()
{
	dp.push_back(0);dp.push_back(1);dp.push_back(2);dp.push_back(3);

	for(ll i=4;i<=pow(10,7);i++)
	{
		ll temp = dp[i/2] + dp[i/3] + dp[i/4];
		ll ans = max(temp,i);
		dp.push_back(ans);
	}
	return;
}

ll maxProfit(ll n)
{
	if(n<=pow(10,7))
	{
		return dp[n];
	}
	ll q1 = maxProfit(n/2) + maxProfit(n/3) + maxProfit(n/4);
	ll q2 = n;
	ll ans = max(q1,q2);
	return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    maxProfitcalc(); 
   	ll ans = maxProfit(n);
    cout<< ans <<endl;
    return 0;
}