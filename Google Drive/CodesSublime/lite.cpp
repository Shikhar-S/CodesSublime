#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n;
int getSize(int x)
{
	int ans=1;
	while(ans<x)
		ans<<=1;
	return ans<<1|1;
}
struct node{
	int on,off;
};
node *tree;
int *lazy;
node combine(node &a,node &b)
{
	node c;
	c.on=a.on+b.on;
	c.off=a.off+b.off;
	return c;
}
void build(int present,int seg_start,int seg_end)
{
	if(seg_start>seg_end)return;
	if(seg_end==seg_start)
	{
		tree[present].on=0;
		tree[present].off=1;
		
		return;
	}
	int mid=seg_start+(seg_end-seg_start)/2;
	build(present<<1,seg_start,mid);
	build(present<<1|1,mid+1,seg_end);
	tree[present]=combine(tree[present<<1],tree[present<<1|1]);
	
}
void update(int present,int seg_start,int seg_end,int l,int r)
{
	if(lazy[present])
	{
		
		{
			lazy[present]=0;
			swap(tree[present].on,tree[present].off);
		}
		if(seg_start!=seg_end)
		{
			lazy[present<<1]=!lazy[present<<1];
			lazy[present<<1|1]=!lazy[present<<1|1];
		}
		
	}
	if(seg_end<seg_start || l>seg_end || r<seg_start)
		return;
	if(l<=seg_start && r>=seg_end)
	{
		swap(tree[present].on,tree[present].off);
		if(seg_start!=seg_end)
		{
			lazy[present<<1]=!lazy[present<<1];
			lazy[present<<1|1]=!lazy[present<<1|1];
		}
		
		return;	
	}
	int mid=seg_start+(seg_end-seg_start)/2;
	update(present<<1,seg_start,mid,l,r);
	update(present<<1|1,mid+1,seg_end,l,r);
	tree[present]=combine(tree[present<<1],tree[present<<1|1]);
}
node query(int present,int seg_start,int seg_end,int l,int r)
{
	if(seg_end<seg_start || l>seg_end || r<seg_start)
	{
		node c;
		c.on=0;
		c.off=0;
		return c;
	}
	if(lazy[present])
	{
		
		
			lazy[present]=0;
			swap(tree[present].on,tree[present].off);
		
		if(seg_start!=seg_end)
		{
			lazy[present<<1]=!lazy[present<<1];
			lazy[present<<1|1]=!lazy[present<<1|1];
		}
		
	}
	if(l<=seg_start && r>=seg_end)
	{
		return tree[present];
	}
	int mid=seg_start+(seg_end-seg_start)/2;
	node c=query(present<<1,seg_start,mid,l,r);
	node d=query(present<<1|1,mid+1,seg_end,l,r);
	return combine(c,d);
}
int main()
{
	int m;
	scanf("%d %d",&n,&m);
	int s=getSize(n);
	tree=new node[s];
	lazy=new int[s];
	build(1,0,n-1);
	for(int i=0;i<s;i++)
		lazy[i]=0;
	while(m--)
	{
		int sw,l,r;
		scanf("%d %d %d",&sw,&l,&r);
		if(sw==1)
		{
			printf("%d\n",query(1,0,n-1,l,r).on);;
		}
		else
		{
			update(1,0,n-1,l,r);
			/*for(int i=1;i<s;i++)
				printf("%d %d",tree[i].on,tree[i].off);
			printf("\n");*/
		}
	}
}