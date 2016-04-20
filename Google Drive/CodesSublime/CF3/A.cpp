#include <iostream>
#include <algorithm>
using namespace std;
int mod(int x,int y)
{
	if(x<0)
	{
		int ans=x%y;
		return ans+y-1;
	}
	else
		return x%y;
}
int main()
{
	int n,a,b;
	cin>>n>>a>>b;
	int ans=a;
	if(b>0)
	for(int i=1;i<=b;i++)
	{
		if(ans==n)
			ans=1;
		else
			ans++;
	}
	else
	{
		b=-b;
		for(int i=1;i<=b;i++)
	{
		if(ans==1)
			ans=n;
		else
			ans--;
	}
	}
	cout<<ans<<endl;
}