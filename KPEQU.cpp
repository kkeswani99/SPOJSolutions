#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll sieve[10001];
ll arr[100000];
void make_sieve()
{
    sieve[2] = 1;
    for(ll i = 4;i<10001;i+=2) sieve[i] = 0;
    ll k = 1;
    for(ll i=3;i<10001;i+=2){
        if(sieve[i]){
            for(ll j = i*i;j<10001;j+=i){
                sieve[j] = 0;
            }
        }
    }
    return ;
}

ll f2(ll n,ll p)
{
    ll ans = 0;
    ll x = p;
    while( (n/x) > 0){
        ans = ans + (n/x);
        x = x*p;
    }
    return ans;
}


void multiply(ll mul,ll &len)
{
    ll carry = 0;
    ll i = 0;
    while(i<len)
    {
        arr[i] = arr[i]*mul + carry;
        carry = arr[i]/10;
        arr[i] = arr[i]%10;
        i++;
    }
    while(carry!=0)
    {
        arr[i] = carry%10;
        carry = carry/10;
        i++;
    }
    len = i;
    return ;
}

void f(ll n){
    ll len = 1;
    memset(arr,0,sizeof(arr));
    arr[0] = 1;
    for(ll i=2;i<=n;i++){
        if(sieve[i]==1){
            ll fac = f2(n,i);
            multiply(2*fac+1,len);
        }
    }
    for(ll i = len-1;i>=0;i--)
        cout<<arr[i];
    cout<<endl;
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(ll i=0;i<10001;i++) sieve[i] = 1;
    make_sieve();
    while(true){
        ll n;
        cin>>n;
        if(n==0)
            return 0;
        f(n);
    }
    return 0;
}