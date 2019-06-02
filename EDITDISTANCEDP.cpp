#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll minoperations(string a, string b,ll lena,ll lenb)
{
	//Converting b to a
	ll dp[lena+1][lenb+1];
	for(ll i=0;i<=lena;i++)
		for(ll j=0;j<=lenb;j++)
			dp[i][j] = 0;

	for(ll i=0;i<=lenb;i++)
		dp[0][i] = i;

	for(ll i=0;i<=lena;i++)
		dp[i][0] = i;

	//Now we fill the main dp table
	for(ll i=1;i<=lena;i++)
	{
		for(ll j=1;j<=lenb;j++)
		{
			if(a[i-1]==b[j-1])
				dp[i][j] = dp[i-1][j-1];
			else
				dp[i][j] = min(1+dp[i-1][j-1],min(1+dp[i][j-1],1+dp[i-1][j]));
		}
	}
	return dp[lena][lenb];
}

int main()
{
    ll test;
    cin>>test;
    while(test--)
    {
    	string a,b;
    	cin>>a;
    	cin>>b;
    	ll ans = minoperations(a,b,a.length(),b.length());
    	cout<< ans <<endl;
    }
    return 0;
}