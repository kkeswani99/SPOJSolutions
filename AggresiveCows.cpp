#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll check_possibilty(ll *a,ll dist,ll c,ll n)
{
	ll cows = 1;//assuming i have placed cow at first position;
	ll pos = a[0];
	for(ll i=1;i<n;i++)
	{
		if(a[i]-pos>=dist)
		{
			cows++;
			pos = a[i];
			if(cows==c)
				return 1;
		}
	}
	return 0;
}

ll binsearch(ll *a,ll n,ll c)
{
	ll s = a[0];
	ll e = a[n-1];
	ll max=1;
	while(s<=e)
	{
		ll mid = (s+e)/2;
		ll check = check_possibilty(a,mid,c,n);
		if(check==1)
		{
			s = mid+1;
			max = mid;
		}
		else 
		{
			e = mid-1;
		}
	}
	return max;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //ll test;
    //cin>>test;
    //while(test--)
    //{
    	ll st,c;
    	cin>>st>>c;
    	ll a[st];
    	
    	for(ll i=0;i<st;i++)
    		cin>>a[i];

    	sort(a,a+st);
    	ll ans = binsearch(a,st,c);
    	cout<< ans <<endl;
    //}
    return 0;
}