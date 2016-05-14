#include <cstdio>
#include <algorithm>
#include <climits>
typedef long long int ll;
using namespace std;
ll arr[50005];
int n;
struct node
{
	ll sum,left,right,ans;
};
node *tree;
ll getSize(int x)
{
	ll ans=1;
	while(ans<x)
		ans<<=1;
	return ans<<1|1;
}
ll finalmax(ll a,ll b,ll c,ll d,ll e){
	ll t=a;
	t=t>b?t:b;
	t=t>c?t:c;
	t=t>d?t:d;
	t=t>e?t:e;
	return t;
}
node combine(node &a,node &b)
{
	node c;
	c.sum=a.sum+b.sum;
	c.left=max(a.left,a.sum+b.left);
	c.right=max(b.right,a.right+b.sum);
	c.ans=finalmax(a.right+b.left,c.left,c.right,a.ans,b.ans);
	return c;
}
node intial(ll x)
{
	node c;
	c.sum=x;
	c.left=x;
	c.right=x;
	c.ans=x;
	return c;
}
void build(ll present,ll seg_start,ll seg_end)
{
	if(seg_start>seg_end)return;
	if(seg_start==seg_end)
	{
		tree[present]=intial(arr[seg_start]);
		return;
	}
	ll mid=seg_start+(seg_end-seg_start)/2;
	build(present<<1,seg_start,mid);
	build(present<<1|1,mid+1,seg_end);
	tree[present]=combine(tree[present<<1],tree[present<<1|1]);
}
node query(ll present,ll l,ll r,ll seg_start,ll seg_end)
{
	if(seg_end==r && seg_start==l)
		return tree[present];
	ll mid=seg_start+(seg_end-seg_start)/2;
	if(l>mid)
		return query(present<<1|1,l,r,mid+1,seg_end);
	if(r<=mid)
		return query(present<<1,l,r,seg_start,mid);
	node a=query(present<<1,l,mid,seg_start,mid);
	node b=query(present<<1|1,mid+1,r,mid+1,seg_end);
	return combine(a,b);
}
int main(){
	scanf("%d",&n);
	for(int i = 0; i < n; ++i)
	{
		scanf("%lld",&arr[i]);
	}
	tree=new node[getSize(n)];
	build(1,0,n-1);
	ll q;
	scanf("%lld",&q);
	while(q--)
	{
		ll l,r;
		scanf("%lld %lld",&l,&r);
		l--;r--;
		printf("%lld\n",query(1,l,r,0,n-1).ans);
	}
}