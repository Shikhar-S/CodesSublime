#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int main()
{
	int t;cin>>t;
	while(t--)
	{
		ll n,k;
		cin>>n>>k;
		ll a[n];
		ll b[n];
		for(int i=0;i<n;i++)
			cin>>a[i];

		
		for (int i=0;i<n;i++)
		{
			cin>>b[i];
		}
		ll ans=0;
		ll idx=0;
		ll temp=abs(b[0]);
		for(int i=0;i<n;i++)
		{
			if(abs(b[i])>temp)
			{
				temp=abs(b[i]);
				idx=i;
			}
			ans=ans+(a[i]*b[i]);
		}
		ans=ans+(b[idx]<0?(b[idx]*-k):(b[idx]*k));
		cout<<ans<<"\n";
	}
}