#include <stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	int arr[51];
	arr[0]=1;arr[1]=1;arr[2]=1;
	arr[3]=2;
	int i;
	for(i=4;i<=50;i++)
		arr[i]=arr[i-1]+arr[i-3];
	while(t--)
	{
		int n;
		scanf("%d",&n);
		printf("%d\n",arr[n]);
	}
	return 0;
}