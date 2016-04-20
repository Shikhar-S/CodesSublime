#include <iostream>
#include <string>
using namespace std;
int main()
{
	int t;
	cin>>t;
	int j=0;
	while(t--)
	{
		j++;
		string x;
		cin>>x;
		int n=x.length();
		int dp[n];
		dp[0]=(x[0]=='-')?1:0;
		for(int i=1;i<n;i++)
		{
			if(x[i]=='+')
			{
				dp[i]=dp[i-1];
			}
			else
			{
				int k;
				for(k=i-1;k>=0;k--)
				{
					if (x[k]!='-')
					{
						dp[i]=dp[k]+2;
						break;
					}
				}
				if (k==-1)
				{
					dp[i]=1;
				}
			}
		}
		cout<<"Case #"<<j<<": "<<dp[n-1]<<"\n";
	}
}