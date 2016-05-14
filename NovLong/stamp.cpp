#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>
#include <climits>
using namespace std;
vector<pair<int,int> > *edges;
int *startingStamps;
int *maxPossible;
bool *visited;
bool *visited1;
vector<int> *graph;
void update(int x,int y)
{
	visited1[x]=true;
	for(vector<int>::iterator it=graph[x].begin();it!=graph[x].end();it++)
	{
		if(!visited1[*it])
		{
			update(*it,y);
		}
	}
	maxPossible[x]=y;
}
int dfs(int x,int fill)
{
	visited[x]=true;
	for(vector<int>::iterator it=graph[x].begin();it!=graph[x].end();it++)
	{
		if(!visited[*it])
			fill=dfs(*it,max(fill,maxPossible[*it]));
	}
	return fill;

}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		edges=new vector<pair<int,int> >[50001];
		maxPossible=new int[200001];
		for(int i=0;i<200001;i++)
			maxPossible[i]=i;
		int n,m;
		cin>>n>>m;
		startingStamps=new int[n];
		for(int i=0;i<n;i++)
			cin>>startingStamps[i];
		for(int i=0;i<m;i++)
		{
			int a,b,c;
			cin>>a>>b>>c;
			edges[a].push_back(make_pair(b,c));
		}
		for(int j=50000;j>0;j--)
		{
			if(!edges[j].empty())
			{
				graph=new vector<int>[200001];
				visited=new bool[200001];
				memset(visited,false,sizeof(visited));
				visited1=new bool[200001];
				memset(visited1,false,sizeof(visited1));
				for(vector<pair<int,int> >::iterator it=edges[j].begin();it!=edges[j].end();it++)
				{ 
					graph[it->first].push_back(it->second);
					graph[it->second].push_back(it->first);	
				}
				
				for(int i=1;i<200001;i++)
				{
					if(!visited[i] && !graph[i].empty())
					{
						int m=dfs(i,maxPossible[i]);
						update(i,m);
					}
				}
				//delete[] graph;
				//delete[] visited;
				//delete[] visited1;
			}
		}
		long long int ans=0;
		for(int i=0;i<n;i++)
			ans+=(maxPossible[startingStamps[i]]);
		cout<<ans<<endl;
		//delete[] maxPossible;
		//delete[] startingStamps;
		//delete[] edges;
	}
}