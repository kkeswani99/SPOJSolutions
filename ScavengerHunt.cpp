#include <bits/stdc++.h>
#define ll long long int
using namespace std;

//We will be making a generic graph which will work for all datatypes
// Template for a generic graph
template<typename T>
class Graph
{
	std::map< T,list<T> > adjList;
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
	void printAdjList()
	{
		//Iterate over map
		for(auto row:adjList)
		{
			T key = row.first;
			cout<<key<<"-->";
			for(T element:row.second)
			{
				cout<<element<<",";
			}
			cout<<endl;
		}
	}

	void bfstopologicalsort()
	{
		queue<T> q;
		map<T, bool> visited;
		map<T,ll> indegree;
		for(auto i:adjList)
		{
			// i is a pair of a node and a list
			T node = i.first;
			visited[node] = false;
			indegree[node] = 0;
		}
		// Init the indegree of all the nodes
		for(auto i:adjList)
		{
			T u = i.first;
			for(T v:adjList[u]){
				indegree[v]++;
			}
		}
		// Find out all the nodes with indegree 0;
		for(auto i:adjList)
		{
			T node = i.first;
			if(indegree[node]==0)
			{
				q.push(node);
			}
		}
		//Start with the algorithm
		while(!q.empty())
		{
			T node = q.front();
			q.pop();
			cout<<node<<endl;
			for(T neighbour:adjList[node])
			{
				indegree[neighbour]--;
				if(indegree[neighbour]==0)
				{
					q.push(neighbour);
				}
			}
		}
	}
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll test;
    cin>>test;
    for(ll i=1;i<=test;i++)
    {
    	Graph<string> G;
    	ll steps;
    	cin>>steps;
    	for(ll i=1;i<steps;i++)
    	{
    		string u,v;
    		cin>>u>>v;
    		G.addEdge(u,v,false);
    	}
    	cout<<"Scenario #"<<i<<":"<<endl;
        G.bfstopologicalsort();
        cout<<endl;
	}
    return 0;
}