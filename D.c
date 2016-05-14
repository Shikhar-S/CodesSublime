#include<stdio.h>
int n;
void dfs(int x,int visited[],int arr[][n])
{
	int i;
	visited[x]=1;
	for(i=0;i<n;i++)
	{
		if(arr[x][i] && !visited[i])
		{
			dfs(i,visited,arr);
		}
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int m;
		scanf("%d %d",&n,&m);
		int arr[n+1];
		int visited[n+1];
		int g[n][n];
		int i,j;
		for(i=0;i<n+1;i++)
			{
				visited[i]=0;
				arr[i]=0;
			}
		for(i=0;i<n;i++)
			for (j = 0; j<n; ++j)
			{
				g[i][j]=0;
			}
		for(i=0;i<m;i++)
		{
			int x,y;
			scanf("%d %d",&x,&y);
			g[x-1][y-1]=1;
			g[y-1][x-1]=1;
			arr[x]++;
			arr[y]++;
		}
		int connected=1;
		for (int i = 0; i < n; ++i)
		{
			if (arr[i+1]>0)
			{
				dfs(i,visited,g);
				break;
			}
		}
		
		for (int i = 0; i <n; ++i)
		{
			if (visited[i]==0 && arr[i+1]>0)
			{
				connected=0;
				break;
			}
		}
		if(connected)
		{
			int odd=0;
			for(i=0;i<n+1;i++)
			{
				if(arr[i]%2==1)
					odd++;
			}
			if(odd==0)printf("Eulerian circuit\n");
			else if(odd==2)
				printf("Eulerian path\n");
			else
				printf("neither\n");
		}
		else
				printf("neither\n");
			
		
	}
	return 0;
}