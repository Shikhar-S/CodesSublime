#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
	int t;cin>>t;
	
	string x;
	cin>>x;
	int n=x.length();
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	bool mark[n];
	for(int i=0;i<n;i++)
		mark[i]=false;
	int cur=0;
	while(cur>=0 && cur<=n-1)
	{
		if(mark[cur])
		{
			cout<<"INFINITE\n";
			return 0;
		}
		mark[cur]=true;
		if(x[cur]=='<')
		{
			cur=cur-arr[cur];
		}
		else if(x[cur]=='>')
		{
			cur=cur+arr[cur];
		}
	}
	cout<<"FINITE\n";
}