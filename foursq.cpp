#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define left(x) (x<<1)
#define right(x) (x<<1|1)
using namespace std;
typedef long long ll;
vector<ll> pprimes;
bool isprime[1003];
ll tree[6*100005],A[100005],P;
pair<ll,ll> pp[100005];
ll output[10];

ll mulmod(ll a,ll b,ll mod)
{
    ll res=0;
    while(a!=0)
    {
        if(a&1)
            res=(res+b)%mod;
        a>>=1;
        if(b<mod-b)
        {
            b<<=1;
        }
        else
        {
            b-=(mod-b);
        }
    }
    return res;
}
void preprocess()
{
    pp[0]=mp(0,0);
    for(int i=1;i<=100000;i++)
    {
        ll a=sqrt(i);
        pp[i]=mp(-1,-1);
        for(int j=1;j<=a;j++)
        {
            ll b=sqrt(i-j*j);
            if((b*b+j*j)==i)
            {
                pp[i]=mp(b,j);
                break;
            }
        }
    }
    for(int i=1;i<101;i++)
        isprime[i]=true;
    for(int i=2;i<101;i++)
        if(isprime[i])
        {
            pprimes.pb(i);
            for (int j=i*2;j<101;j+=i)
                isprime[j]=false;
        }
}
bool frsqr(ll c,ll v,ll m)
{
	if(v==0)
    {
		for(int i=c;i<4;i++)
            output[i]=0;
		return true;
	}
	for(int i=0;i<pprimes.size() && (pprimes[i]*pprimes[i])<=v;i++)
    {
		while((v%(pprimes[i]*pprimes[i]))==0)
        {
            v/=pprimes[i];
            v/=pprimes[i];
			m*=pprimes[i];
		}
	}
	ll d=sqrt(v);
    ll r=301;
	if(c==2)
    {
		if(pp[v].ff<0) 
            return false;
		output[c]=m*pp[v].ff;
		output[c+1]=m*pp[v].ss;
		return true;
	}
	
	if(c==1) 
        r=6;
	for(int i=1;i<=r;i++)
    {
		if(v<d*d)
			return false;
		output[c]=m*d;
		if(frsqr(c+1,v-d*d,m))
			return true;
        d--;
	}
	return false;
}
void update(ll n,ll s,ll e,ll idx,ll val){
    if(s==e)
    {
        A[idx]=val;
        tree[n]=val;
    }
    else
    {
        ll m=s+(e-s)/2;
        if(idx<=m)
            update(left(n),s,m,idx,val);
        else
            update(right(n),m+1,e,idx,val);
 
        tree[n]=mulmod(tree[left(n)],tree[right(n)],P);
    }
}
ll query(ll n,ll s,ll e,ll l,ll r){
	if(r<s || e<l)
		return (ll)1;
	if(l<=s && e<=r)
		return tree[n];
	ll m=s+(e-s)/2;
	ll p1=query(left(n),s,m,l,r);
	ll p2=query(right(n),m+1,e,l,r);
	return mulmod(p1,p2,P);
}
void build(ll n,ll s,ll e){
    if(s==e)
        tree[n]=A[s];
    else
    {
        ll m=s+(e-s)/2;
        build(left(n),s,m);
        build(right(n),m+1,e);
        tree[n]=mulmod(tree[left(n)],tree[right(n)],P);
    }
}
 
int main()
{
    ll t;
    ll n,m;
    scanf("%lld",&t);
    preprocess();
    while(t--)
    {
    	scanf("%lld %lld %lld",&n,&m,&P);
    	for(int i=0;i<n;i++)
    	   scanf("%lld",A+i);
 
    	build(1,0,n-1);
        ll i,l,r;
    	while(m--)
        {
    		scanf("%lld %lld %lld",&i,&l,&r);
    		if(i==1)
            {
    			update(1,0,n-1,l-1,r);
    		}
            else
            {
    			ll ans=query(1,0,n-1,l-1,r-1);
                //cout<<ans<<endl;
				frsqr(0,ans,1);
                for(int k=0;k<4;k++)
				    printf("%lld ",output[k]);
                printf("\n");
    			
    		}
    	}
    }
    return 0;
}