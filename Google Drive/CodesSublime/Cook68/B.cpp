#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
int main()
{
	int t;
	cin>>t;
	int hh[]={0,1,2,3,4,5,6,7,8,9,11,22,33,44,55,66,77,88,99};
	int mm[]={0,1,2,3,4,5,6,7,8,9,11,22,33,44,55,66,77,88,99};
	while(t--)
	{
		int h,m;
		cin>>h>>m;
		int i=0,j=0;
		int ans=0;
		while(i<19 && hh[i]<h)
		{
			while(j<19 && mm[j]<m)
			{
				
				if(hh[i]%10==mm[j]%10)
				ans++;
				j++;
			}
			j=0;
			i++;
		}
		cout<<ans<<endl;
	}
}