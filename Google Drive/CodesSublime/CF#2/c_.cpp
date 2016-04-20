#include <iostream>
#include <vector>
using namespace std;
vector<int> arr[100005];
int main()
{
	int n,d,h;
	cin>>n>>d>>h;
	d++;h++;
	if (d==2 && h==2 &&n>2)
	{
		cout<<-1<<endl;
		return 0;
	}
	if(d==h && n>2)
	{
		for(int i=2;i<=d;i++)
		{
			arr[i-1].push_back(i);
		}
		for(int j=d+1;j<=n;j++)
		{
			arr[2].push_back(j);
		}
		for(int i=1;i<=n;i++)
		{
			int sz=arr[i].size();
			for(int j=0;j<sz;j++)
			{
				cout<<i<<" "<<arr[i][j]<<"\n";
			}
		}
	return 0;
	}
	if((d+1>2*h))
	{
		cout<<-1<<endl;
		return 0;
	}
	int k=2;
	int l=1;
	for(;k<=h;k++)
	{
		arr[l].push_back(k);
		//arr[k].push_back(l);
		l=k;
	}
	l=1;
	for(;k<=d;k++)
	{
		arr[l].push_back(k);
		//arr[k].push_back(l);
		l=k;	
	}
	for(;k<=n;k++)
	{
		arr[1].push_back(k);
		//arr[k].push_back(1);	
	}
	for(int i=1;i<=n;i++)
	{
		int sz=arr[i].size();
		for(int j=0;j<sz;j++)
		{
			cout<<i<<" "<<arr[i][j]<<"\n";
		}
	}
}