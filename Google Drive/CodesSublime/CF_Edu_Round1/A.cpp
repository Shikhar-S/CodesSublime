#include <iostream>
using namespace std;
int main()
{
	int h1,h2;
	cin>>h1>>h2;
	int a,b;cin>>a>>b;
	if(h1==h2)
	{
		cout<<0<<endl;
	}
	else if(a<b && h1+a*8<h2)
	{
		cout<<-1<<endl;
	}
	else if(a==b && h2-h1>8*a)
	{
		cout<<-1<<endl;
	}
	else
	{
		int cur=h1+a*8;
		if(cur>=h2)
			cout<<0<<endl;
		else
		{
			int ans=0;
			while(cur<h2)
			{
				cur-=12*b;
				ans++;
				cur+=12*a;
			}
			cout<<ans<<endl;	
		}
		
	}
}