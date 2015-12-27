#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
long long int mod= 1000000007;
using namespace std;
typedef long long int ll;


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		
		vector<pair<ll,ll> > p;
		for(int i=0;i<n;i++)
		{
			ll x,y;
			cin>>x>>y;
			p.push_back(make_pair(x*y,0));
			p.push_back(make_pair(x*(y+1)-1,1));
			
		}
		
		ll ans=0;
		if(n==k)
		{
			ans=1;
			for(int i=1;i<=100;i++)
			{
				ans=((ans)*10)%mod;
			}
			ans=(ans+1)%mod;
		}
		else
		{
			sort(p.begin(),p.end());
			ll ctr=0;
			
			ll prev;
				for(int i=0;i<p.size();i++)
				{
					if(p[i].second==0)
					{
						ctr++;
						if(ctr==(n-k))
						{
							prev=p[i].first;
						}
					}
					else
					{
						ctr--;
						if(ctr==(n-k-1))
						{
							ans=(ans+p[i].first-prev+1)%mod;
						}
					}
				}
		}
		
		cout<<ans<<endl;
		

	}
	return 0;

}