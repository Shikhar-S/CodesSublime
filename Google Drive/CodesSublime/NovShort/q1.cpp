#include <cstdio>
using namespace std;
typedef long long int ll;
ll gcd(ll n,ll m)
{
	if(n%m == 0)
	   return m;
	else
	   return gcd(m,n%m);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		ll arr[n];
		for(int i=0;i<n;i++)
			scanf("%lld",&arr[i]);
		ll ans=arr[0];
		for(int i=1;i<n;i++)
		{
			ans=gcd(arr[i],ans);
		}
		printf("%lld\n",ans*n);
	}
}