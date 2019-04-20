#include <bits/stdc++.h>
#define ll long long int
using namespace std;
class Graph
{
	ll V;
	list<ll> *adjList;
	public:
	Graph(ll v)
	{
		V = v;
		adjList = new list<ll>[V];
	}
	void addEdge(ll u,ll v,bool bidir=true)
	{
		adjList[u].push_back(v);
		if(bidir)
			adjList[v].push_back(u);
	}
	void printAdjList()
	{
		for(ll i=0;i<V;i++)
		{
			cout<<i<<"-->";
			for(ll node:adjList[i])
			{
				cout<<node<<",";
			}
			cout<<endl;
		}
	}
	void bfs(ll src,ll dest)
	{
		queue<ll> q;
		bool *visited = new bool[V]{0};
		ll *dist = new ll[V+1]{0};
		ll *parent = new ll[V+1];
		for(ll i=0;i<V;i++)
			parent[i] = -1;
		q.push(src);
		visited[src] = true;
		while(!q.empty())
		{
			ll node = q.front();
			q.pop();
			for(ll neighbour:adjList[node])
			{
				if(!visited[neighbour])
				{
					q.push(neighbour);
					visited[neighbour] = true;
					dist[neighbour] = dist[node] + 1;
					parent[neighbour] = node;
				}
			}
		}
        if(dist[dest])
		    cout<<dist[dest]<<endl;
        else
            cout<<-1<<endl;
	}

}; 


int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    ll n,m,s,l;
    while(scanf("%d" , &n) != EOF) {
    cin>>m>>s>>l;
    Graph g(10002);
    ll board[10002] = {0};
    for(ll i=0;i<s;i++)
    {
    	ll h,t;
    	cin>>h>>t;
    	board[h] = -(h-t);
    }
    for(ll i=0;i<l;i++)
    {
    	ll p,q;
    	cin>>p>>q;
    	board[p] = q-p;
    }
    for(ll u=0;u<n*m+1;u++)
    {
    	for(ll dice=1;dice<=6;dice++)
    	{
    		ll v = u + dice + board[u+dice];
            while(board[v]!=0)
                v = v + board[v];
    		g.addEdge(u,v,false);
    	}
    }
    g.bfs(0,n*m);
    }
    return 0;
}