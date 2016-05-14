#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int arr[101][101]={0};
struct queries{
	int t,r,c,v;
};
vector<queries> v(10001);
int main()
{
	int n,m,q;
	cin>>n>>m>>q;
	
	for(int i=0;i<q;i++)
	{
		int x;cin>>x;
		v[i].t=x;
		if(x==1 || x==2)
		{
			int y;cin>>y;
			v[i].r=y;
		}
		else
		{
			int a,b,c;
			cin>>a>>b>>c;
			v[i].r=a;
			v[i].c=b;
			v[i].v=c;
		}
	}
	for(int i=q-1;i>=0;i--)
	{
		if(v[i].t==3)
		{
			arr[v[i].r][v[i].c]=v[i].v;
		}
		else if(v[i].t==1)
		{
			int row=v[i].r;
			arr[row][0]=arr[row][m];
			for(int j=m;j>=1;j--)
			{
				arr[row][j]=arr[row][j-1];
			}

		}
		else if(v[i].t==2)
		{
			int col=v[i].r;
			arr[0][col]=arr[n][col];
			for(int j=n;j>=1;j--)
			{
				arr[j][col]=arr[j-1][col];
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cout<<arr[i][j]<<' ';
		}
		cout<<endl;
	}
}
