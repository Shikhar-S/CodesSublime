#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
typedef long long ll;
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n];
		int ans[n];
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
			ans[i]=0;
		}
		for(int i=0;i<n;i++)
		{
			int c=i;
			if(i!=0 && ans[i-1])
			{
				ans[i]=ans[i-1]-1;
			}
			else
			{
				for(int j=i+1;j<n;j++)
				{
					if((arr[c]>0 && arr[j]<0) || (arr[c]<0 && arr[j]>0))
					{
						ans[i]++;
						c++;
					}
					else
						break;
				}
			}
		}
		for(int i=0;i<n;i++)
			cout<<ans[i]+1<<" ";
		cout<<endl;
		
	}
}