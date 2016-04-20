#include <cstdio>
#include <iostream>
using namespace std;
typedef long long int ll;
char s[]={'N','E','S','W'};
ll bit[1005][1005];
ll n,m;
void update(ll x,ll y,ll k){
    while(x<=m)
    {
        ll t=y;
        while(t<=n){
            bit[x][t]+=k;
            t+=(t&-t);
        }
        x+=(x&-x);
    }
}
ll get(ll x,ll y){
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
ll mod(ll x,ll y){
	if ((x%y)>=0){
		return x%y;
	}
	else
	{
		return (x%y)+y;
	}
}
int main(){
    
    scanf("%lld %lld",&m,&n);
    //cin>>n>>m;
    ll arr[m+1][n+1];
    for(ll i=1;i<=m;i++){
        char str[n+1];
        scanf(" %s",str);
        for(ll j=1;j<=n;j++){
            
            if(str[j-1]=='N')
                arr[i][j]=0;
            else if(str[j-1]=='E')
                arr[i][j]=1;
            else if(str[j-1]=='S')
                arr[i][j]=2;
            else
                arr[i][j]=3;
        }
    }
    ll q;
    scanf("%lld",&q);
    //cin>>q;
    while(q--){
        char sw;
        scanf(" %c",&sw);
        //cin>>sw;
        switch(sw){
            case 'C':
            {
                ll x1,y1,x2,y2,k,v=0;
                scanf("%lld %lld %lld %lld %lld",&x1,&y1,&x2,&y2,&k);
                //cin>>x1>>y1>>x2>>y2>>k;
                if(k==0)
                    v=1;
                else
                    v=-1;
                update(x1,y1,v);
                update(x1,y2+1,-v);
                update(x2+1,y1,-v);
                update(x2+1,y2+1,v);
                break;
                
            }
            case 'D':
            {
                ll x1,y1;
                scanf("%lld %lld",&x1,&y1);
                //cin>>x1>>y1;
                char ch=s[mod((get(x1,y1)+arr[x1][y1]),4)];
                printf("%c",ch);
                if(q!=0)printf("\n");
                
            }
        }
    }
}