#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
vector<pair<int,int> > *v;
bool *visited;
int answer[3001][3001];
int dijkstra(int present,int ans,int final)
{
	visited[present]=true;
	if(final==present)
		return ans;
	/*else if (answer[present][final]!=-1)
	{
		return answer[present][final];
	}*/
	else
	{
		for(vector<pair<int,int> >::iterator it=v[present].begin();it!=v[present].end();it++)
		{
			if(!visited[it->first])
			ans=max(ans,dijkstra(it->first,min(it->second,ans),final));
		}
		answer[present][final]=ans;
	}
	return ans;
}
int main()
{
	int x;
	int e;
	cin>>x>>e;
	v=new vector<pair<int,int> >[x+1];
	
	visited=new bool[x+1];
	for(int i=0;i<=x;i++)
	{
		visited[i]=false;
		for(int j=0;j<=x;j++)
			answer[i][j]=-1;
	}
		
	for(int i=0;i<e;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		v[a].push_back(make_pair(b,c));
		v[b].push_back(make_pair(a,c));
	}
	for(int i=1;i<=x;i++)
	{
		for(int j=i+1;j<=x;j++)
		{
			if(answer[i][j]==-1)
			{
				for(vector<pair<int,int> >::iterator it=v[i].begin();it!=v[i].end();it++)
				{
					if(!visited[it->first])
					answer[i][j]=max(answer[i][j],dijkstra(it->first,it->second,j));
				}
			}
		}
	}
	for(int i=1;i<=x;i++)
	{
		for(int j=1;j<=x;j++)
		{
			if (i!=j) 
				cout<<answer[i][j]<<" ";
			else
				cout<<0<<" ";
		}
		cout<<endl;
	}
	
}