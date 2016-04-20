#include <iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int s;cin>>s;
		int ans=0;
		for(int i=1;i<=s;i++)
		{
			int x;cin>>x;
			if(x%2!=0)
				ans^=i;
		}
		if(ans)
			cout<<"Tom Wins\n";
		else
			cout<<"Hanks Wins\n";
	}
}