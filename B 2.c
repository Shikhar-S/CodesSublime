#include <stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int ans=1;
		int m,n;
		scanf("%d %d",&m,&n);
		if(m<n)
		{
			int temp=m;
			m=n;
			n=temp;
		}
		int arr[n+1];

		int i,j;
		for(i=0;i<=n;i++)
			arr[i]=0;
		for(i=m+n;i>m;i--)
		{
			int flag=0;
			for(j=n;j>0 && !flag;j--)
			if(i%j==0 && !arr[j])
			{
				ans*=(i/j);
				arr[j]=1;
				flag=1;
				break;
			}

			if(!flag)
			{
				ans*=i;
			}
			
		}
		for(i=1;i<=n;i++)
			if(!arr[i])
				ans/=i;
		printf("%lld\n",ans);
	}
	return 0;
}