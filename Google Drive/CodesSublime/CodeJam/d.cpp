#include <iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	int j=0;
	while(t--)
	{
		j++;
		int k,c,s;
		cin>>k>>c>>s;
		cout<<"Case #"<<j<<":";
		for(int i=1;i<=k;i++)
		{
			cout<<" "<<i;
		}
		cout<<endl;
	}
}