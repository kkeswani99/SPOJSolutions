#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll sieve[32001];
ll arr[10000];
void make_sieve()
{
    for(ll i=0;i<=32000;i++)
        sieve[i] = 1;
	arr[0] = 2;
	ll k = 1;
	for(ll i=3;i<=180;i+=2){
		if(sieve[i]==1)
		{
			for(ll j = i*i;j<=32000;j+=i)
				sieve[j] = 0;
		}
	}   
	for(ll i=3;i<=32000;i++)
	{
		if(sieve[i]==1)
		{
			arr[k] = i;
			k++;
		}
	}
	return ;
}

ll f(ll n)
{
	ll k = 0;
	ll ans = 1;
	for(ll i = arr[k];i*i<=n;i=arr[k++])
	{
		ll ct = 0;
		while(n%i==0){
			ct++;
			n = n/i;
		}
		ans = ans*(ct + 1);
	}
	if(n!=1)
	{
		ans = ans*2;
	}
	return ans;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   	ll a,b,n; 
   	cin>>a>>b>>n;
   	make_sieve();
   	ll f_ans = 0;
   	for(int i=a;i<=b;i++)
   	{
   		ll ans = f(i);
   		if(ans==n)
   			f_ans++;
   	}
   	cout<< f_ans <<endl;
   	return 0;
}