#include <cstdio>
#include <algorithm>
using namespace std;
struct node
{
	int l,r;
};
node *tree;
int *arr;
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
	int tmp=min(a.l,b.r);
	c.l=a.l+b.l-tmp;
	c.r=a.r+b.r-tmp;
	return c;
}
void build(int present,int start,int end)
{
	if(start==end)
	{
		if(arr[start]){
			tree[present].l=1;
			tree[present].r=0;
		}
		
		else
		{
			tree[present].r=1;
			tree[present].l=0;
		}
		
		return;
	}
	int mid=start+(end-start)/2;
	build(present<<1,start,mid);
	build(present<<1|1,mid+1,end);
	tree[present]=combine(tree[present<<1],tree[present<<1|1]);
}
void update(int present,int start,int end,int idx)
{
	
	if(start==end)
	{
		if(arr[idx]){
			tree[present].l=1;
			tree[present].r=0;
		}
		
		else
		{
			tree[present].r=1;
			tree[present].l=0;
		}
		
		
		return;
	}
	int mid=start+(end-start)/2;
	if(idx<=mid)
		update(present<<1,start,mid,idx);
	else
		update(present<<1|1,mid+1,end,idx);
	tree[present]=combine(tree[present<<1],tree[present<<1|1]);

}
node query(int present,int start,int end,int l,int r)
{
	
	if(l==start && r==end)
		return tree[present];
	int mid=start+(end-start)/2;
	if(l>mid)
		return query(present<<1|1,mid+1,end,l,r);
	if (r<=mid)
		return query(present<<1,start,mid,l,r);
	node a=query(present<<1,start,mid,l,mid);
	node b=query(present<<1|1,mid+1,end,mid+1,r);
	return combine(a,b);
}
int main()
{
	int t=10;
	while(t--)
	{
		printf("Test %d:\n",(10-t));
		int n;
		scanf("%d",&n);
		arr=new int[n];
		tree=new node[size(n)];
		for (int i = 0; i < n; ++i)
		{
			char ch;
			scanf(" %c",&ch);
			if(ch=='(')
				arr[i]=1;
			else
				arr[i]=0;
		}
		build(1,0,n-1);
		/*for(int i=0;i<n;i++)
			printf("%d ",arr[i]);
		printf("\n");
		*/int m;
		scanf("%d",&m);
		while(m--)
		{
			int v;
			scanf("%d",&v);
			if(v==0)
			{
				node temp=query(1,0,n-1,0,n-1);
				if(temp.l==0 && temp.r==0)
					printf("YES\n");
				else
					printf("NO\n");
			}
			else
			{
				v--;
				arr[v]=arr[v]==1?0:1;

				update(1,0,n-1,v);
				/*for(int i=1;i<size(n);i++)
					printf("%d %d",tree[i].l,tree[i].r);
				printf("\n");*/
			}
		}
		delete[] tree;
		delete[] arr;
	}
}