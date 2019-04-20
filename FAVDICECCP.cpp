#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main() {
    ll t;
    cin>>t;
    while(t--)
    {
        long double n;
        cin>>n;
        long double ans = 0;
        for(float i=1.00;i<=n;i++)
            ans = ans + (n/i);
        cout<<fixed<<setprecision(2)<<ans<<endl;
    }
    return 0;
}