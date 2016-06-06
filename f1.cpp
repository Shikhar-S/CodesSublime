#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;
int arr[1003][1003];
int BIT_min[1003][1003]={INT_MAX};
int BIT_sum[1003][1003]={0};
int n,m;
void update_m(int x,int y,int val)
{
	for(int i=1;i<=n;i+=(i&-i))
	{
		for(int j=1;j<=m;j+=(j&-j))
		{
			BIT_sum[i][j]=min((arr[x][y]);
		}
	}
}
void query_m(int x,int y,int val)
{
	for(int i)
}
void update_s(int x,int y,int val)
{
	for(int i=1;i<=n;i+=(i&-i))
	{
		for(int j=1;j<=m;j+=(j&-j))
		{
			BIT_sum[i][j]+=(arr[x][y]);
		}
	}
}
void query_s(int x,int y,int val)
{
	
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&arr[i][j]);

}