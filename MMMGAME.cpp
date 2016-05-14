#include <iostream>
using namespace std;
int main()
{
	int t;cin>>t;
	while(t--)
	{
		int n;cin>>n;
		bool check=false;
		int ans=0;
		while(n--)
		{
			int x;cin>>x;
			if(x>1)check=true;
			ans=ans^x;
		}
		if((check && ans==0) || (!check && ans==1))
			cout<<"Brother\n";
		else
			cout<<"John\n";
	}
}