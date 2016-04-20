#include <iostream>
#define mod 1000000007
using namespace std;
typedef long long ll;
int main()
{
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		char str[1002];
		cin>>str;
		ll ans=1;
		int c=0;
		int n=strlen(str);
		for(int i=1;i<n-1;i++)
		{
			if(str[i]!=str[i-1] && str[i]!=str[i+1] && str[i-1]!=str[i+1])
				c=3;
			else if(str[i]==str[i-1] && str[i]==str[i+1])
				c=1;
			else
				c=2;
			ans=((ans%mod)*c)%mod;
		}
		if(n>1)
		{
			c=str[0]!=str[1]?2:1;
			ans=((ans%mod)*c)%mod;
			c=str[n-1]!=str[n-2]?2:1;
			ans=((ans%mod)*c)%mod;
		}
		cout<<"Case #"<<i<<": "<<ans<<"\n";
	}
}