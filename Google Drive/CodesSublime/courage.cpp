#include <cstdio>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;
typedef long long int ll;
struct node
{
	ll sum;
	ll m;
};
node *tree;
ll *arr;
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
node combine(node &a,node &b)
{
	node c;
	c.sum=a.sum+b.sum;
	c.m=min(a.m,b.m);
	return c;
}
int getSegmentTreeSize(int N) {
    int size = 1;
    for (; size < N; size <<= 1);
    return size << 1;
  }
void build(int present,int l,int r)
{
	if(r<l)return;
	if (l==r)
	{
		tree[present].sum=arr[l];
		tree[present].m=arr[l];
		return;
	}
	int mid=l+(r-l)/2;

	build(present<<1,l,mid);
	build(present<<1|1,mid+1,r);
	tree[present]=combine(tree[present<<1],tree[present<<1|1]);
}
void update(int present,int l,int r,int idx,int val)
{
	if (r<l)return;
	if(r==l)
	{
		tree[present].sum+=val;
		tree[present].m+=val;
		return;
	}
	int mid=l+(r-l)/2;
	if(idx>mid)
		update(present<<1|1,mid+1,r,idx,val);
	else
		update(present<<1,l,mid,idx,val);
	tree[present]=combine(tree[present<<1],tree[present<<1|1]);
}
node query(int present,int start,int end,int l,int r)
{
	if(start>end || l>end || start>r)
	{
		node a;
		a.sum=0;
		a.m=INT_MAX;
		return a;
	}
	if(start==r && end==l)
	{
		return tree[present];
	}
	int mid=start+(end-start)/2;
	if (l>mid)
	{
	 	return query(present<<1|1,mid+1,end,l,r);
	}
	if(r<=mid)
		return query(present<<1,start,mid,l,r);
	node a=query(present<<1,start,mid,l,mid);
	node b=query(present<<1|1,mid+1,end,mid+1,r);
	return combine(a,b);
}
int main()
{
	int n;
	scanf("%d",&n);
	arr=new ll[n];
	tree=new node[4*n+5];
	for(int i=0;i<n;i++)
	{
		arr[i]=scan();
	}
	build(1,0,n-1);
	int q;
	scanf("%d",&q);
	while(q--)
	{
		char x[8];
		scanf("%s",x);
		int a=scan();
		int b=scan();
		if(x[0]=='C')
		{
			
			node temp=query(1,0,n-1,a,b);
			printf("%lld\n",(temp.sum-temp.m));
		}
		else if(x[0]=='G')
		{
			
			update(1,0,n-1,b,a);
		}
		else{
			
			update(1,0,n-1,b,-a);
		}
	}


}
