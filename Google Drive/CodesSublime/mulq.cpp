#include <cstdio>
#include <algorithm>
using namespace std;
struct node{
	int rz,ro,rt;
};
int *lazy;
node *tree;

int size(int x)
{
	int ans=1;
	while(ans<x)
		ans<<=1;
	return ans<<1|1;
}
node combine(node &a,node &b)
{
	node c;
	c.rz=a.rz+b.rz;
	c.ro=a.ro+b.ro;
	c.rt=a.rt+b.rt;
	return c;
}
node updlazy(int x,int present)
{
	node c=tree[present];
	if(x%3==1)
	{
		swap(c.rz,c.ro);
		swap(c.rz,c.rt);
	}
	else if(x%3==2)
	{
		swap(c.rz,c.rt);
		swap(c.rz,c.ro);
	}
	return c;
}
void build(int present,int l,int r)
{
	if(l>r) return;
	if(l==r)
	{
		tree[present].rz=1;
		tree[present].ro=0;
		tree[present].rt=0;
		return;
	}
	int mid=l+(r-l)/2;
	build(present<<1,l,mid);
	build(present<<1|1,mid+1,r);
	tree[present]=combine(tree[present<<1],tree[present<<1|1]);
}
void update(int present,int l,int r,int start,int end){
	if(lazy[present]){
		tree[present]=updlazy(lazy[present],present);
		if(start!=end){
			lazy[present<<1]+=lazy[present];
			lazy[present<<1|1]+=lazy[present];
		}
		lazy[present]=0;
	}
	if(l>end || r<start || start>end)
		return;
	if(l<=start && r>=end)
	{
		tree[present]=updlazy(1,present);
		if(start!=end){
			lazy[present<<1]+=1;
			lazy[present<<1|1]+=1;
		}	
		return;
	}
	int mid=start+(end-start)/2;
	update(present<<1,l,r,start,mid);
	update(present<<1|1,l,r,mid+1,end);
	tree[present]=combine(tree[present<<1],tree[present<<1|1]);

}
node query(int present,int l,int r,int start,int end){
	if(l>end || r<start || start>end)	
	{
		node c={0,0,0};
			return c;
	}
	if(lazy[present]){
		tree[present]=updlazy(lazy[present],present);
		if(start!=end){
			lazy[present<<1]+=lazy[present];
			lazy[present<<1|1]+=lazy[present];
		}
		lazy[present]=0;
	}
	if(l<=start && r>=end)
	{
		return tree[present];
	}
	int mid=start+(end-start)/2;
	node a=query(present<<1,l,r,start,mid);
	node b=query(present<<1|1,l,r,mid+1,end);
	return combine(a,b);
}
int main(){
	int n,q;
	scanf("%d %d",&n,&q);
	int s=size(n);
	tree=new node[s];
	lazy=new int[s];
	build(1,0,n-1);
	while(q--){
		int sw,l,r;
		scanf("%d %d %d",&sw,&l,&r);
		//l++;r++;
		switch(sw){
			case 0:
			{
				update(1,l,r,0,n-1);
				break;
			}
			case 1:
			{
				printf("%d\n",query(1,l,r,0,n-1).rz);
				break;
			}
		}
	}
}