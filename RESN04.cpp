#include <iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;cin>>n;
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			int x;cin>>x;
			ans+=(x/i);
		}
		if(ans%2==1)
			cout<<"ALICE\n";
		else
			cout<<"BOB\n";
	}
}