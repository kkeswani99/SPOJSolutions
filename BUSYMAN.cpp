#include <bits/stdc++.h>
#define ll long long int
using namespace std;

//Comparator function to sort elements according to secone element
bool sortbysec(pair<ll,ll> &a,pair<ll,ll> &b)
{
	return (a.second<b.second);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll test;
    cin>>test;
    while(test--)
    {
    	ll n;
    	cin>>n;
    	vector< pair<ll,ll> > sch;
    	for(ll i=0;i<n;i++)
    	{
    		ll a,b;
    		cin>>a>>b;
    		sch.push_back(make_pair(a,b));
    	}
		//sorting vector of pairs
    	sort(sch.begin(),sch.end(),sortbysec);
    	ll count = 1;
    	ll finish = sch[0].second;
    	for(ll i=1;i<n;i++)
    	{
    		if(sch[i].first>=finish)
    		{
    			count++;
    			finish = sch[i].second;
    		}
    	}
    	cout<< count <<endl;    
    }
    return 0;
}