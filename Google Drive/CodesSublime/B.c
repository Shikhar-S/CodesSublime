#include <stdio.h>
#include <limits.h>
int n;
int min(int a,int b)
{
	return a<b?a:b;
}
int max(int a,int b)
{
	return a>b?a:b;
}
void dijkstra(int g[][n],int visited[],int dist[][n],int i,int j,int c,int x)
{
	int k;
	
	if(x!=j)
	{
		visited[x]=1;
		for(k=0;k<n;k++)
		{
			if(g[x][k] && !visited[k])
			{
				dijkstra(g,visited,dist,i,j,c+1,k);
			}
		}
		visited[x]=0;
	}
	
	else
	dist[i][j]=min(dist[i][j],c);
}
void reset(int visited[])
{
	int i;
	for(i=0;i<n;i++)
	{
		visited[i]=0;
	}
}
int main()
{
	int e;
	scanf("%d %d",&n,&e);
	int g[n][n];
	int dist[n][n];
	int visited[n];
	int i,j;
	for(i=0;i<n;i++)
	{
		visited[i]=0;
		for(j=0;j<n;j++)
			{
				if(i==j)dist[i][i]=0;
				else
					dist[i][j]=INT_MAX;
				g[i][j]=0;
			}
	}
		
	for(i=0;i<e;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		g[x][y]=1;
		g[y][x]=1;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i!=j)
			dijkstra(g,visited,dist,i,j,0,i);
			reset(visited);
		}
			
	}
	int r,d;
	r=INT_MAX;
	d=INT_MIN;

	for(i=0;i<n;i++)
	{
		int temp=INT_MIN;
		for(j=0;j<n;j++)
		{
			//printf("%d ",dist[i][j]);
			temp=max(dist[i][j],temp);
		}
		//printf("\n");
		r=min(temp,r);
		d=max(temp,d);
	}
	printf("%d %d",r,d);
	return 0;
}