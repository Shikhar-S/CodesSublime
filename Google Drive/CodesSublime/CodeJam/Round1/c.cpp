#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
int getLen(bool visited[],i,vector<int> &v,ans)
{
	if (visited[i])
	{
		return ans;
	}
	visited[i]=true;
	for(int j=0;j<v[i].length();j++)
	{
		if(!visited[v[i][j]])
		{
			ans=getLen(visited,v[i][j],v,ans+1);
		}
	}
	return ans;
}
int main()
{
	int t;
	//bitset<int>
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		printf("Case #%d: ",i);
		int n;scanf("%d",&n);
		int arr[n+1];
		vector<int> v[1001];
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&arr[i]);
			v[i].push_back(arr[i]);
			v[arr[i]].push_back(i);
		}
		for(int i=1;i<=n;i++)
		{
			if(arr[arr[i]]==i)
			{
				visited[arr[i]]=true;
				int l=dfs(visited,arr[i],v,0);
			}
		}
		bool visited[1001]={false};
		int ans=INT_MIN;
		for(int i=1;i<=1000;i++)
		{
			int l=getLen(visited,i,v,0);
			for(int j=1;j<1001;j++)
				visited[j]=false;
			ans=max(ans,l);
		}
		printf("%d\n",ans);
		
	}
}