#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int result[1000005]={0};
int main()
{
	int transitions=0;
	int n,q;
	cin>>n>>q;
	int cur=1;
	int temp=0;
	int flag=false;
	int initialVal=0;
	for(int i=0;i<q;i++)
	{
		int x;cin>>x;
		if(x==1)
		{
			int y;cin>>y;
			temp+=y;
			if(temp>n)
				temp=temp-n;
			else if (temp<1)
			{
				temp=temp+n;
			}
		}
		else
		{
			if((cur%2==0 && temp%2==0) || (cur%2==1 && temp%2==1)) 
			{
				transitions--;
			}
			else
			{
				transitions++;
			}
			cur+=temp;
			if (cur>n)
			{
				cur-=n;
			}
			else if (cur<1)
			{
				cur+=n;
			}
			if (!flag)
			{
				flag=true;
				initialVal=cur;
			}
			temp=0;
		}
	}
	if(initialVal%2==1)
	{
		int c=1;
		int j=transitions+initialVal;
		if(j>n)
			j-=n;
		for(;result[j]==0;j+=2)
		{
			if(j>n)
				j-=n;
			result[j]=c;
			c+=2;
		}
		j=transitions+initialVal+1;
		if(j>n)
			j-=n;
		c=2;
		for(;result[j]==0;j+=2)
		{
			if(j>n)
				j-=n;
			result[j]=c;
			c+=2;
		}

	}
	else
	{
		int c=2;
		int j=transitions+initialVal;
		if(j>n)
			j-=n;
		for(;result[j]==0;j+=2)
		{
			if(j>n)
				j-=n;
			result[j]=c;
			c+=2;
		}
		j=transitions+initialVal-1;
		if(j>n)
			j-=n;
		c=1;
		for(;result[j]==0;j+=2)
		{
			if(j>n)
				j-=n;
			result[j]=c;
			c+=2;
		}

	}
	for(int i=cur;i<=n;i++)
		cout<<result[i]<<" ";
	for(int i=1;i<cur;i++)
	{
		cout<<result[i]<<" ";
	}
}