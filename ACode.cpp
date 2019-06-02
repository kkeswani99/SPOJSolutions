//Solved!!!
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

string s;
int a[5000];
ll dp[5000] = {0};
ll f(ll i)
{
	if(s[i+1]=='\0')
	{
		if(a[i]>=1 && a[i]<=9)
			return 1;
		else
			return 0;
	}
	if(dp[i]!=-1)
		return dp[i];
	ll ans = 0;
	if(a[i]>=1 && a[i]<=9)
	{
		ans = ans + f(i+1);
		if(a[i]==1)
		{
			if(s[i+2]!='\0')
				ans = ans + f(i+2);
			else
				ans = ans + 1;
		}
		if(a[i]==2 && (a[i+1]>=0 && a[i+1]<=6))
		{
			if(s[i+2]!='\0')
				ans = ans + f(i+2);
			else
				ans = ans + 1;	
		}
	}
	return dp[i] = ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(true)
    {
    	s.clear();
    	memset(a,0,sizeof(a));
    	memset(dp,-1,sizeof(dp));
    	cin>>s;

    	if(s[0]=='0'&&s[ 1]=='\0')
    		return 0;
    	
    	for(ll i=0;s[i]!='\0';i++)
    		a[i] = s[i] - '0';
    	
    	ll ans = f(0);
    	cout<< ans <<endl;
    }
    return 0;
}