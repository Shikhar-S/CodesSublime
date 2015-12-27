#include <stdio.h>
int main()
{
	int t,i;
	scanf("%d",&t);
	while(t--)
	{
		char A[102];
		char B[102];
		scanf("%s",A);
		scanf("%s",B);
		int s=A[0]-B[0];
		s=s>0?s:-s;
		int m=s;int p=-1;
		for(i=1;i<=5;i++)
		{
			if(s%i==0 && (s/i)>=m)
			{
				m=s/i;
				p=i;
			}
			s+=26;
		}
		printf("%d %d\n",m,p);
	}
}