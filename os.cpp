#include <cstdio>
#include <algorithm>
#include <unordered_map>
using namespace std;
typedef long long int ll;
unordered_map<ll,ll> mp;
ll arr[200005];
ll v[200005];
ll n=0;
struct queries{
    ll num;
    char ch;
};
ll get(ll x){
    ll ans=0;
    for(;x>0;x-=(x&-x)){
        ans+=arr[x];
    }
    return ans;
}
void update(ll x,ll val){
    for(;x<=n;x+=(x&-x)){
        arr[x]+=val;
    }
}
ll fnd(ll x){
    ll l=1,r=n;
    ll idx=-1;
    while(l<=r){
        ll mid=l+(r-l)/2;
        ll temp=get(mid);
        if(temp==x){
            if(get(mid-1)!=temp){
                idx=mid;
                break;
            }
            else
            {
                r=mid-1;
            }
        }
        else if(temp>x){
            r=mid-1;
        }
        else
            l=mid+1;
    }
    return idx;
}
ll f(ll x){
    ll l=0,r=n;
    ll ans=-1;
    while(l<=r){
        ll mid=l+(r-l)/2;
        if(v[mid]==x){
            ans=mid;
            break;
        }
        else if(v[mid]<x && v[mid+1]>x){
            ans=mid;
            break;
        }
        else if(v[mid]>x){
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    return ans;
}
int main(){
    for(ll i=0;i<=200004;i++){
        arr[i]=0;
        v[i]=0;
    }
    ll qu;
    scanf("%lld",&qu);
    queries q[qu];
    for(ll i=0;i<qu;i++){
        scanf(" %c %lld",&q[i].ch,&q[i].num);
        if(mp.find(q[i].num)==mp.end()){
            v[++n]=q[i].num;
            mp[q[i].num]=n;
        }
    }
    n++;
    sort(v+1,v+n);
    for (ll i=1; i<n; i++) {
        mp[v[i]]=i;
    }
   
    for(ll i=0;i<qu;i++){
        ll no=q[i].num;
        char ch=q[i].ch;
        switch(ch){
            case 'I':
            {
                ll t=mp[no];
                if(get(t)==get(t-1))
                {
                	update(t,1);
                	
                }
                break;
            }
                
            case 'D':	{
                //unordered_map<ll,ll>::iterator it=mp.find(no);
                //if(it!=mp.end()){
                    if(get(mp[no])!=get(mp[no]-1)){
                        update(mp[no],-1);
                        
                    }
                    
                //}
                break;
                
            }
                
            case 'K':	{
                ll idx=-1;
                if(no<=get(n) && no>0)
                    idx=fnd(no);
                if(idx!=-1)
                    printf("%lld\n",v[idx]);
                else
                    printf("invalid\n");
                break;
            }
                
            case 'C':
                ll ans=0;
                
                
                {
                    /*ll a=f(no);
                    if(v[a]==no){
                        ans=get(mp[v[a]])-1;
                    }
                    else{
                        ans=get(mp[v[a]]);
                    }*/
                        ans=get(mp[no]-1);
                }
                printf("%lld\n",ans);
        }
    }
}