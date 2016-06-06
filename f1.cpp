#include <cstdio>
#include <algorithm>
#include <climits>
#define VAL 1000000
using namespace std;
int arr[1003][1003];
int BIT_sum[1003][1003]={0};
int n,m;
struct node{
	int x;
	int y;
	int max_val;
	node(int x, int y, int mx) : x(x), y(y), max_val(mx) {}
	bool operator < (const node& other) const {
        return max_val < other.max_val;
    }
};
class Segtree{
public:
	node T[VAL];
	int n,m;
public:
	Segtree(int r,int c)
	{
		n=r;
		m=c;
		build(1,1,1,n,m);
	}
	node empty()
	{
		return node(0,0,INT_MIN);
	}
	
	node build(int current,int a1,int b1,int a2,int b2)
	{
		if (a1 > a2 || b1 > b2)
			return empty();
		if (a1 == a2 && b1 == b2)
            return T[current] = node(a1, b1, arr[a1][b1]);
        T[current]=empty();
        T[current]=max(T[current],build(4 * current - 2, a1, b1, (a1 + a2) / 2, (b1 + b2) / 2 ));
        T[current]=max(T[current],build(4*current-1,(a1 + a2) / 2 + 1, b1, a2, (b1 + b2) / 2 ));
        T[current]=max(T[current],build(4*current,a1, (b1 + b2) / 2 + 1, (a1 + a2) / 2, b2));
        T[current]=max(T[current],build(4*current+1,(a1 + a2) / 2 + 1, (b1 + b2) / 2 + 1, a2, b2));
        return T[current];
	}
	node query(int current,int a1,int b1,int a2,int b2,int x1,int y1,int x2,int y2)
	{
		if (x1 > a2 || y1 > b2 || x2 < a1 || y2 < b1 || a1 > a2 || b1 > b2)
			return empty();
		if (x1 <= a1 && y1 <= b1 && a2 <= x2 && b2 <= y2)
			return T[current];
		node mx=empty();
		mx=max(T[current],query(4 * current - 2, a1, b1, (a1 + a2) / 2, (b1 + b2) / 2 ,x1,y1,x2,y2));
		mx=max(T[current],query(4*current-1,(a1 + a2) / 2 + 1, b1, a2, (b1 + b2) / 2 ,x1,y1,x2,y2));
		mx=max(T[current],query(4*current,a1, (b1 + b2) / 2 + 1, (a1 + a2) / 2, b2,x1,y1,x2,y2));
		mx=max(T[current],query(4*current+1,(a1 + a2) / 2 + 1, (b1 + b2) / 2 + 1, a2, b2,x1,y1,x2,y2));
		return mx;
	}
	node query(int x1, int y1, int x2, int y2) {
        return query(1, 1, 1, n, m, x1, y1, x2, y2);
    }
    
};
Segtree T_MAX;
void update_s(int x,int y,int val)
{
	for(int i=x;i<=n;i+=(i&-i))
	{
		for(int j=y;j<=m;j+=(j&-j))
		{
			BIT_sum[i][j]+=(arr[x][y]);
		}
	}
}
int query_s(int x,int y)
{
	int sum=0;
	for(int i=x;i>0;i-=(i&-i))
	{
		for(int j=y;j>0;j-=(j&-j))
		{
			sum+=BIT_sum[i][j];
		}
	}
	return sum;
}
int main()
{
	int x;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&arr[i]);
			update_s(i,j,arr[i]);
			update_s(i+1,j,-(arr[i]));
			update_s(i,j+1,-(arr[i]));
			update_s(i+1,j+1,arr[i]);
		}

	T_MAX.init(n,m);
	int q;
    scanf("%d",&q);
    while(q--)
    {
    	int a,b;
    	scanf("%d %d",&a,&b);
    	int ans=INT_MAX;
    	int sum=0;
    	int mx=0;
    	int sz=0;
    	a--;b--;
    	for(int i=1;i+b<=n;i++)
    	{
    		for(int j=1;j+a<=m;j++)
    		{
    			sum=query_s(i+a,j+b)+query_s(i-1,j-1)-query_s(i+a,j-1)+query_s(i-1,j+b);
    			mx=T_max.query(i,j,i+a,j+b)max_val;
    			sz=(a)*(b);
    			ans=min(ans,sz*mx-sum);
    		}
    	}
    	printf("%d\n",ans);
    }
}
