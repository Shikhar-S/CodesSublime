#include <iostream>
#include <set>
#include <vector>
using namespace std;
set<int> arr[100001]; 
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int x,y;cin>>x>>y;
		arr[x].insert(y);
		arr[y].insert(x);
	}
	set<int> a;
	set<int> b;
	a.insert(n);
	int ans=1;
	int c=0;
	for(int i=n-1;i>0;i--)
	{
		if(arr[i].empty() && c==0)
		{
			c++;
			ans=2;
		}	
		else if (arr[i].empty() && c!=0)
		{
			ans=1;
		}
		else if(*(arr[i].rbegin()) > i)
		{
			continue;
		}
		else
		{
			
		}
	}
	cout<<ans<<endl;

}