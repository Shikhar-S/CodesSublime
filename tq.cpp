#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long int ll;
inline ll scan(){
    char c = getchar_unlocked();
    ll x = 0;
    while(c<'0'||c>'9'){
        c=getchar_unlocked();
    }
    while(c>='0'&&c<='9'){
        x=(x<<1)+(x<<3)+c-'0';
        c=getchar_unlocked();
    }
    return x;
}
struct values{
    ll v;
    ll idx;
};
ll bit[100002];
values arr[100002];
ll mp[100002];
ll n;
bool comp(values &a,values & b){
    return a.v<b.v;
}
inline void update(ll x,ll val){
    for(;x<=n;x+=(x&-x))
        bit[x]+=val;
}
inline ll get(ll x){
    ll ans=0;
    for(;x>0;x-=(x&-x))
        ans+=bit[x];
    return ans;
}
inline ll leftmost(ll x){

    ll l=1,r=n;
    
    while(l<r){
        ll mid=(r+l)>>1;
        if(get(mid)>=x){
            r=mid;
        }
        else
        {
            l=mid+1;
        }
    }
    return l;
}
int main(){
    ll m;
    bit[0]=0;
    n=scan();
    bit[n+1]=0;
    m=scan();
    //scanf("%lld %lld",&n,&m);
    for(ll i=1;i<=n;i++){
        //scanf("%lld",&arr[i].v);
        bit[i]=0;
        arr[i].v=scan();
        arr[i].idx=i;
    }
    arr[0].v=0;
    sort(arr+1,arr+n+1,comp);
    for(int i=1;i<=n;i++)
    {
        mp[arr[i].idx]=i;
        update(i,arr[i].v-arr[i-1].v);
    }
    for(ll i=0;i<m;i++){
        ll a;
        ll b;
        //scanf("%d %lld",&a,&b);
        a=scan();
        b=scan();
        switch (a){
            case 1:
            {
                /****************************
                consider array 12,21,31,31,31,32,37
                adding 1 at position 3 should tamper the sorting
                hence we first swap pos 3 with pos 5
                and then add 1 at pos 5 instead.
                ****************************/
                ll x=get(mp[b]);//gets value at original idx b
                ll y=arr[leftmost(x+1)-1].idx;//gets rightmost index with value same as above
                swap(mp[y],mp[b]);//swaps end elements in a series,say of 31s,to keep list sorted
                arr[mp[b]].idx=b;//to complete the swap
                arr[mp[y]].idx=y;
                update(mp[b],1);//now update the rightmost element in the series
                update(mp[b]+1,-1);
                break;
            }
            case 2:
            {
            	if(b>get(n)){
            		printf("0\n");

            	}
            	else
            	{
            		ll idx=leftmost(b);
               		printf("%lld\n",(n-idx+1));	
            	}
                
                
                break;
            }
            case 3:
            {
            	if(b<=get(n)){
                    update(leftmost(b),-1);
                }
                
                break;
            }
        }
    }
}