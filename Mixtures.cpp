#include <bits/stdc++.h>
using namespace std;

int a[101];
long long int dp[101][101];

int sum(int i,int j)
{
	int ans = 0;
	for(int k=i;k<=j;k++)
		ans = (ans + a[k])%100;
	return ans;
}


long long int solveMix(int i,int j)
{
	if(i>=j){
        return 0;
    }
	if(dp[i][j]!=-1)
    {
		return dp[i][j];
    }

	dp[i][j] = INT_MAX;
	for(int k=i;k<=j;k++)
	{
		dp[i][j] = min(dp[i][j],solveMix(i,k)+solveMix(k+1,j)+sum(i,k)*sum(k+1,j));
	}
	return dp[i][j];
}

int main()
{
    int n;
    while((scanf("%d",&n))!=EOF)
    {
    	for(int i=0;i<n;i++)
    		cin>>a[i];
    	for(int i=0;i<=n;i++)
    		for(int j=0;j<=n;j++)
    			dp[i][j] = -1;
    	cout<<solveMix(0,n-1)<<endl;
    }
    return 0;
}