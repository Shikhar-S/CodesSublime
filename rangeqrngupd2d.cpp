#include <cstdio>
using namespace std;
typedef long long int ll;
ll b1[1005][1005];
ll b2[1005][1005];
ll b3[1005][1005];
ll b4[1005][1005];
ll n;
inline ll scan( ) {
	ll n=0;
	ll ch=getchar_unlocked();
	while( ch <48 )ch=getchar_unlocked();
	while( ch >47 )
	n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
	return n;
}
void update(ll x,ll y,ll k, ll bit[][1005]){
    while(x<=n){
        ll t=y;
        while(t<=n){
            bit[x][t]+=k;
            t+=(t&-t);
        }
        x+=(x&-x);
    }
}
ll query(ll x,ll y,ll bit[][1005]){
    ll ans=0;
    while(x){
        ll t=y;
        while(t){
            ans+=bit[x][t];
            t-=(t&-t);
        }
        x-=(x&-x);
    }
    return ans;
}
int main(){
    ll m;
    scanf("%lld %lld",&n,&m);
    for(ll i=0;i<1005;i++)
        for(ll j=0;j<1005;j++)
        {
        	b1[i][j]=0;
        	b2[i][j]=0;
        	b3[i][j]=0;
        	b4[i][j]=0;
        }
           // bit[i][j]=0;
    while(m--){
        ll sw;
        scanf("%lld",&sw);
        switch(sw)
        {
            case 1:
            {
                ll x1,y1,x2,y2;
                ll ans=0;
                x1=scan();y1=scan();x2=scan();y2=scan();
                //scanf("%lld %lld %lld %lld",&x1,&y1,&x2,&y2);
                long long val1=query(x2,y2,b1)*x2*y2+query(x2,y2,b2)*x2+query(x2,y2,b3)*y2+query(x2,y2,b4);
		        long long val2=query(x2,y1-1,b1)*x2*(y1-1)+query(x2,y1-1,b2)*x2+query(x2,y1-1,b3)*(y1-1)+query(x2,y1-1,b4);
		        long long val3=query(x1-1,y2,b1)*(x1-1)*y2+query(x1-1,y2,b2)*(x1-1)+query(x1-1,y2,b3)*y2+query(x1-1,y2,b4);
		        long long val4=query(x1-1,y1-1,b1)*(x1-1)*(y1-1)+query(x1-1,y1-1,b2)*(x1-1)+query(x1-1,y1-1,b3)*(y1-1)+query(x1-1,y1-1,b4);
		        
		        ans=val1-val2-val3+val4;
                
                printf("%lld\n",ans);
                break;


            }
            case 2:
            {
                ll x1,y1,x2,y2,k;
                x1=scan();y1=scan();x2=scan();y2=scan();k=scan();
				//scanf("%lld %lld %lld %lld %lld",&x1,&y1,&x2,&y2,&k);
				update(x1,y1,k,b1);
		        update(x1,y2+1,-k,b1);
		        update(x2+1,y1,-k,b1);
		        update(x2+1,y2+1,k,b1);
		        
		        update(x1,y1,k*(1-y1),b2);
		        update(x1,y2+1,k*y2,b2);
		        update(x2+1,y1,k*(y1-1),b2);
		        update(x2+1,y2+1,-y2*k,b2);
		        
		        update(x1,y1,k*(1-x1),b3);
		        update(x1,y2+1,k*(x1-1),b3);
		        update(x2+1,y1,k*x2,b3);
		        update(x2+1,y2+1,-x2*k,b3);
		        
		        update(x1,y1,(x1-1)*(y1-1)*k,b4);
		        update(x1,y2+1,-y2*(x1-1)*k,b4);
		        update(x2+1,y1,-x2*(y1-1)*k,b4);
		        update(x2+1,y2+1,x2*y2*k,b4);
		        //ans+=(sum[x2][y2]-sum[x2][y1-1]-sum[x1-1][y2]+sum[x1-1][y1-1]);

                	
            }
        }
    }
}