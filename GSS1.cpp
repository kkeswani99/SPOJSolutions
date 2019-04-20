#include <bits/stdc++.h>
#define ll long long int
using namespace std;

struct node {
	ll sum,maxsum,prefix_sum,suffix_sum;
};

node tree[400000];

void buildTree(ll *a,ll s,ll e,ll index)
{
	// Base Case - Leaf Node 
	if(s==e)
	{
		tree[index].sum = a[s];
		tree[index].maxsum = a[s];
		tree[index].prefix_sum = a[s];
		tree[index].suffix_sum = a[s];
		return; 
	}
	ll mid = (s+e)/2;
	buildTree(a,s,mid,2*index+1);
	buildTree(a,mid+1,e,2*index+2);
	
	tree[index].sum = tree[2*index+1].sum + tree[2*index+2].sum;

	tree[index].prefix_sum = max(tree[2*index+1].prefix_sum,tree[2*index+1].sum + tree[2*index+2].prefix_sum);

	tree[index].suffix_sum = max(tree[2*index+2].suffix_sum,tree[2*index+1].suffix_sum+tree[2*index+2].sum);

	tree[index].maxsum = max(tree[index].prefix_sum,
						 max(tree[index].suffix_sum,
						 max(tree[2*index+1].maxsum,
						 max(tree[2*index+2].maxsum,tree[2*index+1].suffix_sum + tree[2*index+2].prefix_sum))));

	return ;
}

node query(ll *a,ll ss,ll se,ll qs,ll qe,ll index)
{
	node ans;
	ans.sum = ans.maxsum = ans.prefix_sum = ans.suffix_sum = INT_MIN;

	// No overlap
	if(qs>se || qe<ss)
		return ans;

	if(qs<=ss && qe>=se)
		return tree[index];

	ll mid = (ss + se)/2;

	//right subtree
	if(qs>mid)
		return query(a,mid+1,se,qs,qe,2*index+2);
	//left subtree
	if(qe <= mid)
		return query(a,ss,mid,qs,qe,2*index+1);

	node left = query(a,ss,mid,qs,qe,2*index+1);
	node right = query(a,mid+1,se,qs,qe,2*index+2);

	ans.sum = left.sum + right.sum;
	ans.prefix_sum = max(left.prefix_sum,left.sum + right.prefix_sum);
	ans.suffix_sum = max(right.suffix_sum,left.suffix_sum+right.sum);
	ans.maxsum = max(ans.prefix_sum,
				 max(ans.suffix_sum,
				 max(left.maxsum,
				 max(right.maxsum,left.suffix_sum+right.prefix_sum))));
	return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++)
    	cin>>a[i];
    buildTree(a,0,n-1,0);
    ll q;
    cin>>q;
    while(q--)
    {
    	ll l,r;
    	cin>>l>>r;
    	cout << query(a,0,n-1,l-1,r-1,0).maxsum<<endl;
    }
    return 0;
}