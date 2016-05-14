#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define mod 1000000007
using namespace std;
typedef long long int ll;
int main()
{
	int n,m,c;
	ll temp;
	scanf("%d %d %d",&n,&m,&c);
	ll A[100001]={0};
	ll B[100001]={0};
	ll answer[c+1];
	memset(answer,0,sizeof(answer));
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&temp);
		A[temp]++;
	}
	for(int i=0;i<m;i++)
	{
		scanf("%lld",&temp);
		B[temp]++;
	}
	
	int siz=100001;

	vector<ll> head;
	for(int i=0;i<siz;i++)
	{
		if(A[i]>0 && B[i]>0)
			{
				head.push_back(((A[i]%mod)*(B[i]%mod))%mod);
			}
	}
	siz=head.size();
	ll dp[2][siz];
	
	for(int i=0;i<siz;i++)
	{
		dp[1][i]=0;
		dp[0][i]=head.at(i);
		
	}
		
	for(int i=1;i<=c && siz>0;i++)
	{
		dp[1][siz-1]=0;
		answer[i-1]=dp[0][siz-1];
		for(int j=siz-2;j>=0;j--)
		{
			dp[1][j]=(head.at(j)*(answer[i-1]%mod))%mod;
			answer[i-1]=(answer[i-1]%mod+dp[0][j]%mod)%mod;
		}
		for(int k=0;k<siz;k++)
			dp[0][k]=dp[1][k];
	}
	
	for(int i=1;i<=c;i++)
		cout<<answer[i]<<" ";
} 