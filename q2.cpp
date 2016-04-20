#include <iostream>
#include <list>
#include <algorithm>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		list<int> l;
		int arr[n];
		int ans=0;
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
			if(arr[i]==0)
			{
				l.push_front(i+1);
			}
			else
			{
				int x=0;
				int n=l.size();
				for(list<int>::iterator it=l.begin();it!=l.end();it++)
				{
					x++;
					if(*it==arr[i])
					{
						it++;
						l.insert(it,i+1);
						ans+=min(x,n-x);
						break;
					}
					
				}
			}
		}
		cout<<ans<<endl;
	}
}