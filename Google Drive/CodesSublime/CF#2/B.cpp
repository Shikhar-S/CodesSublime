#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;
int n,k;
priority_queue<int> online;
vector<int> temp(k);
int arr[150005];
int main()
{
	IOS;
	int q;
	cin>>n>>k>>q;
	//int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	
	//int c=0;
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		if(x==1)
		{
			online.push(arr[y-1]);
		}
		else if(x==2)
		{
			//sort(online,online+n,cmp);
			//int idx=binsrch(online,arr[y-1]);
			//cout<<idx<<'\n';
			temp.clear();
			int i;
			int flag=0;
			for(i=0;i<k && !online.empty();i++)
			{
				int ele=online.top();
				temp.push_back(ele);
				online.pop();
				if (ele==arr[y-1])
				{
					cout<<"YES\n";
					flag=1;
					break;
				}

			}

			if(!flag)
				cout<<"NO\n";
			int sz=temp.size();
			for(int i=0;i<sz;i++)
			{
				online.push(temp[i]);
			}
				
		}

	}
}