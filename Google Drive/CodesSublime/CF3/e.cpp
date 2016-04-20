#include <iostream>
#include <vector>
#include <set>
using namespace std;
vector<int> arr[100005];
bool done[100005]={false};
int main()
{
	int n,m;
	cin>>n>>m;
	set<pair<int,int> > s;
	for(int i=0;i<m;i++)
	{
		int x,y;cin>>x>>y;
		arr[x].push_back(y);
		arr[y].push_back(x);

	}
	int cnt=0;
	for(int i=1;i<=n;i++)
		if(arr[i].size()!=0)
		s.insert(make_pair(arr[i].size(),i));
	for(int i=0;i<n;i++)
	{
		int min=(*s.begin()).second;
		done[min]=true;
		arr[min].pop_back();
	}
	for(int i=1;i<=n;i++)
		if(!done[i])
			cnt++;
	cout<<cnt<<endl;
}