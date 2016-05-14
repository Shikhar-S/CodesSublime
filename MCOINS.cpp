#include <iostream>
using namespace std;
int main()
{
	int m,k,l;
	cin>>k>>l>>m;
	int dp[1000002]={0};
	dp[1]=1;
	dp[0]=0;
	for(int i=2;i<1000002;i++)
	{
		int c=dp[i-1];
		c=c&((i-k>=0)?dp[i-k]:1);
		c=c&((i-l>=0)?dp[i-l]:1);
		dp[i]=!c;
	}
	for(int i=0;i<m;i++)
	{
		int x;cin>>x;
		if(dp[x])
		cout<<"A";
		else
		cout<<"B";
	}
	cout<<"\n";
}