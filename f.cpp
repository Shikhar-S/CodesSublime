#include <cstdio>
#include <algorithm>
#include <deque>
using namespace std;
int n,m;
int cun_row[1003][1003];
int cum_col[1003][1003];
void setup()
{
    for(int i=0;i<1003;i++)
    {
        cum_col[i][0]=0;
        cum_row[i][0]=0;
        cum_col[0][i]=0;
        cum_row[0][i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cum_row[i][j]=cum_row[i][j-1]+arr[i][j];
        }
    }
    for(int j=1;j<=m;j++)
    {
        for(int i=1;i<=n;i++)
        {
            cum_col[i][j]=cum_col[i-1][j]+arr[i][j];
        }
    }
}
int getMax(int k,int j,int a)
{
    int ans=INT_MIN;
    for(int i=k;i<=a+k;i++)
    {
        ans=max(ans,arr[i][j]);
    }
}
void update(int k,deque<int> &dq)
{
    while(!dq.empty() && dq.front()<k)
    {
        dq.pop_front();
    }
    dq.push_back(k);
}
int main()
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&arr[i][j]);
		}
    setup();
	int q;
    scanf("%d",&q);
    while(q--)
    {
    	int a,b;
    	scanf("%d %d",&a,&b);
        deque<int> dq;
    	int ans=INT_MAX;
    	int sum=0;
    	int mx=0;
    	int sz=0;
    	a--;b--;
        int prev=INT_MIN;
        for(int i=1;i<=a+1;i++)
        {
            for(int j=1;j<=b+1;j++)
            {
                prev=max(prev,arr[i][j]);
                sum+=arr[i][j];
            }
        }

        for(int i=1;i+a<=n;)
        {
            for(int j=b+2;j+b<=m;j++)
            {
                int t=getMax(i,j,a);
                int old_s=cum_col[i+a][j-b-1]-cum_col[i-1][j-b-1];
                int new_s=cum_col[i+a][j]-cum_col[i-1][j];
                sum+=(new_s-old_s);
                update(t,dq);
                int mx=dq.front();
                ans=min(ans,(mx*(a+1)*(b+1)-sum));
            }
            i++;
            //TODO handle transition between rows
            
            for(int j=m-b-1;j-b>=1;j--)
            {
                int t=getMax(i,j,a);
                int old_s=cum_col[i+a][j+b+1]-cum_col[i-1][j+b+1];
                int new_s=cum_col[i+a][j]-cum_col[i-1][j];
                sum+=(new_s-old_s);
                update(t,dq);
                int mx=dq.front();
                ans=min(ans,(mx*(a+1)*(b+1)-sum));
            }
            i++;
        }
    	printf("%d\n",ans);
    }
}
