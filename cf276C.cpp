#include <cstdio>
#include <algorithm>
#include <climits>
#define lld I64d 
using namespace std;
typedef long long ll;
ll arr[200001];
ll freq[200001];
int main(){
	ll n,q;
	scanf("%lld %lld",&n,&q);
	ll x;
	for(ll i=0;i<200001;i++)
	{
		freq[i]=0;
		arr[i]=0;
	}
	ll query[n+1];
	
	query[0]=0;
	for(ll i=1;i<=n;i++)
		{
			query[i]=0;
			scanf("%lld",&x);
			arr[x]++;
		}
	
	
	for(ll i=0;i<q;i++){
		ll a,b;
		scanf("%lld %lld",&a,&b);
		query[a]++;
		if(b+1<=n)
		query[b+1]--;
	}
	query[0]=0;
	ll c=0;
	for(ll i=1;i<=n;i++){
		c+=query[i];
		freq[c]++;
	}
	
	ll ans=0;
	ll pos=0;
	for(ll i=0;i<200001;i++){
		if(freq[i]){
			while(arr[pos]==0){
				pos++;
			}
			ans+=(pos*i);
			arr[pos]--;
			
			freq[i]--;
			i--;

		}
	}
	printf("%lld\n",ans);
}