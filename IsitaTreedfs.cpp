#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll occ = 0;
template<typename T>
class Graph
{
	map<T, list<T> > adjList;
public:
	Graph()
	{

	}
	void addEdge(T u,T v,bool bidir=true)
	{
		adjList[u].push_back(v);
		if(bidir)
			adjList[v].push_back(u);
	}
	bool isCyclicHelper(T node, map<T,bool> &visited,T parent){
		visited[node] = true;
        occ++;
		for(T neighbour:adjList[node]){
			if(!visited[neighbour]){
				bool cycleDetected = isCyclicHelper(neighbour,visited,node);
				if(cycleDetected){
					return true;
				}
			}
			// In this case neighbour is already visited
			else if(neighbour!=parent)
			{
				return true;
			}
		}
		return false;
	}
	//Check for undirected graph
	bool isCyclicDFS(){
		map<T,bool> visited;
		ll flag = 0;
		for(auto i:adjList){
			T node = i.first;
			if(!visited[node]){
				if(flag==1)
					return true;
				bool ans = isCyclicHelper(node,visited,node);
				flag = 1;
				if(ans)
					return true;
			}
		}
		return false;
	}
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Graph<ll> g;
    ll n,m;
    cin>>n>>m;
    while(m--)
    {
    	ll u,v;
    	cin>>u>>v;
    	g.addEdge(u,v);
    }
    if(g.isCyclicDFS())
    	cout<<"NO"<<endl;
    else
    {
        if(occ==n)
    	    cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}