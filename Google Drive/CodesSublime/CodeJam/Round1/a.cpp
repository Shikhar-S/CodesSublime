#include <iostream>
#include <vector>
#include <set>
#include <climits>
using namespace std;
//vector<int> v[2*51-1];
//int arr[2500+1]={0};
int main()
{
	int t;
	cin>>t;

	//////////////
	
	for(int i=1;i<=t;i++)
	{
		vector<int> v[2*51-1];
		int arr[2500+1]={0};
		int n;cin>>n;
		int ans[n][n];
		
		
		for(int i=0;i<2*n-1;i++)
		{
			for(int j=0;j<n;j++)
			{
				int x;cin>>x;
				v[i].push_back(x);
			}
		}
		set<int> s;
		
		for(int i=0;i<2*n-1;i++)
		{
			for(int j=0;j<n;j++)
			{
				arr[v[i][j]]++;
			}
		}
		for(int i=0;i<2501;i++)
		{
			if(arr[i]%2==1)
				s.insert(i);
		}
		cout<<"Case #"<<i<<": ";
		for(set<int>::iterator it=s.begin();it!=s.end();it++)
			cout<<*it<<" ";
		if(i!=t)
		cout<<'\n';
		///////////
	}
}