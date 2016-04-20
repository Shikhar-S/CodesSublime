#include <iostream>
using namespace std;
typedef long long int ll;
int main()
{
	ll t;
	cin>>t;
	ll j=0;
	while(t--)
	{	j++;
		cout<<"Case #"<<j<<": ";
		ll n;cin>>n;
		if (n==0)
		{
			cout<<"INSOMNIA\n";
			continue;
		}
		ll i=1;
		bool arr[10]={false};
		ll cnt=0;
		for(;cnt<10;i++)
		{
			ll x=n*i;
			while(x)
			{
				ll r=x%10;
				x/=10;
				if (!arr[r])
				{
					arr[r]=true;
					cnt++;
				}
			}
		}
		i--;
		cout<<(n*i)<<endl;
	}
}