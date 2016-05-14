#include <iostream>
using namespace std;
typedef long long int ll;
ll arr[1000001];
ll n;
void update(int x,ll val){
    for(;x<=n;x+=(x&-x)){
        arr[x]+=val;
    }
}
ll get(int x){
    ll ans=0;
    for(;x>0;x-=(x&-x)){
        ans+=arr[x];
    }
    return ans;
}
int main(){
    ll m,c;
    scanf("%lld %lld %lld",&n,&m,&c);
    for(ll i=0;i<m;i++){
        char ch;
        ll num;
        scanf(" %c",&ch);
        switch(ch){
            case 'Q':scanf("%lld",&num);
                printf("%lld\n",get(num)+c);
                break;
            case 'S':ll a,b;
                scanf("%lld %lld %lld",&a,&b,&num);
                update(a,num);
                update(b+1,-num);
                break;
        }
    }
}