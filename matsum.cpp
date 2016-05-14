#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
typedef long long int ll;
ll mat[1025][1025];
ll n;
void update(ll x,ll y,ll val){
	while(x<=n){
		ll t=y;
		while(t<=n){
			mat[x][t]+=val;
			t+=(t&-t);
		}
		x+=(x&-x);
	}
}
ll get(ll x,ll y){
	ll ans=0;
	while(x>0){
		ll t=y;
		while(t>0){
			ans+=mat[x][t];
			t-=(t&-t);
		}
		x-=(x&-x);
	}
	return ans;
}
int main(){
	ll t;
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		for(int i=0;i<=1024;i++){
			for(int j=0;j<=1024;j++)
				mat[i][j]=0;
		}
		while(true){
			char a[5];
			scanf(" %s",a);
			if(a[0]=='E'){
				break;
			}
			else if(a[0]=='S' && a[1]=='E'){
				ll x,y,v;
				scanf("%lld %lld %lld",&x,&y,&v);
				x++;y++;
				int temp=get(x,y)-get(x-1,y)+get(x-1,y-1)-get(x,y-1);
				update(x,y,v-temp);
			}
			else
			{
				ll x1,y1,x2,y2;
				scanf("%lld %lld %lld %lld",&x1,&y1,&x2,&y2);
				x1++;y1++;x2++;y2++;
				ll ans=get(x2,y2)+get(x1-1,y1-1)-get(x1-1,y2)-get(x2,y1-1);
				printf("%lld\n",ans);
			}
		}
		
	}

}