#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    ll var = n&(n-1);
    if(var==0)
    	cout<<"TAK"<<endl;
    else
    	cout<<"NIE"<<endl;
    return 0;
}	