#include <cstdio>
#define MOD 1000000007
typedef unsigned long long int ll;
ll arr[100005];
ll fast_exp(ll x,ll y)
{
    if (y == 0)
        return 1;
    ll p = fast_exp(x,y/2)%MOD;
    p=(p*p)%MOD;
 	return (y%2==0)?p:(x*p)%MOD;
}
int main()
{
	ll t;
	scanf("%llu",&t);
	ll n,x,m;
	while(t--)
	{
		scanf("%llu %llu %llu",&n,&x,&m);
		m-=1;
		for(ll i=0;i<n;i++)
		{
			scanf("%llu",&arr[i]);
			arr[i]=arr[i]%MOD;
		}
		ll c=0,ans=arr[x-1],temp=1;
		for(int i=x-2;i>=0;i--)
		{
			c++;
			temp=(((temp*((c+m%MOD)%MOD))%MOD)*fast_exp(c,MOD-2))%MOD;
			ans+=(arr[i]*temp)%MOD;
			ans=ans%MOD;
		}
		printf("%llu\n",ans);
	}
}