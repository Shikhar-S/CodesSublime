#include <stdio.h>
int n;
void sort(int arr[])
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(arr[j]<arr[j+1])
			{
				int t=arr[j+1];
				arr[j+1]=arr[j];
				arr[j]=t;
			}
		}
	}
	/*for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");*/
}
int checkValid(int arr[])
{
	int flag=1;
	while(flag)
	{
		int i;
		sort(arr);
		if(arr[0]==-999999)break;
		int x=arr[0];
		if(x>=n)flag=0;
		arr[0]=-999999;
		for(i=0;i<=x;i++)
		{
			if(arr[i]!=-999999)
			{
				if(arr[i]-1>=0)
					arr[i]-=1;
				else
					flag=0;
			}
		}
		if (flag)
		{
			flag=checkValid(arr);
		}
		else
			return flag;
	}
	return flag;

}

int star(int arr[])
{
	int i;
	sort(arr);
	if(arr[0]!=(n-1))
		return 0;
	else
	{
		for (i = 1; i < n; ++i)
		{
			if(arr[i]!=1)return 0;
		}
	}
	return 1;
}
int wheel(int arr[])
{
	int i;
	sort(arr);
	if(arr[0]!=(n-1))
		return 0;
	else
	{
		for (i = 1; i < n; ++i)
		{
			if(arr[i]!=3)return 0;
		}
	}
	return 1;
}
int cycle(int arr[])
{
	int i;
	for(i=0;i<n;i++)
		if(arr[i]!=2)
			return 0;
	return 1;
}
int complete(int arr[])
{
	int i;
	for(i=0;i<n;i++)
		if(arr[i]!=(n-1))
			return 0;
	return 1;
}
int main()
{
	int i,j;
	scanf("%d",&n);
	int arr[n];
	int temp[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		temp[i]=arr[i];
	}
	if(checkValid(temp))
	{
		if(complete(arr))
		{
			printf("complete");
		}
		else if (star(arr))
		{
			printf("star");/* code */
		}
		else if (wheel(arr))
		{
			printf("wheel");/* code */
		}
		else if ( cycle(arr))
		{
			printf("cycle");/* code */
		}
		else 
		{
			printf("none");
		}
	}
	else
		printf("invalid");
	return 0;
}