#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll next_higher(ll n)
{
    ll temp = n;
    ll x = 0;
    ll y = 0;
    while(!(temp&1))
    {
        y++;
        temp = temp>>1;
    }
    while(temp&1)
    {
        x++;
        temp = temp>>1;
    }
    if(y==0 && x==32)
        return -1;
    temp = temp|1;
    temp = temp<<(y+x);
    ll mask = 1;
    for(ll i=0;i<x-1;i++)
    {
        temp = temp|mask;
        mask = mask<<1;
    }
    return temp;
}

ll next_smaller(ll n)
{
    ll temp = n;
    ll x = 0;//count of 0
    ll y = 0;//count of 1
    while(temp&1)
    {
        y++;
        temp = temp>>1;
    }
    if(temp==0)
        return -1;
    while(!(temp&1))
    {
        x++;
        temp = temp>>1;
    }
    ll p = x+y;
    n = n & ((~0)<<(p+1));
    ll mask = (1 << (y+1)) - 1;
    n = n | mask << (x-1);
    return n;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll test;
    cin>>test;
    double den = test;
    ll ct = 0;
    double mean = 0;
    while(test--)
    {
        ll n;
        cin>>n;
        if(n==0)
            continue;
        ll srk = next_smaller(n);
        ll sal = next_higher(n);
        if(n*n == sal*srk)
        {
            if(srk>0 && sal>0 && n>=0)
                ct++;
        }
        mean = mean + (sal-srk);
    }
    double num = ct;
    double prob = num/den;
    double stardom_mean = mean/den;
    cout<<fixed<<setprecision(6)<<prob<<" ";
    cout<<fixed<<setprecision(6)<<stardom_mean<<endl;
    return 0;
}