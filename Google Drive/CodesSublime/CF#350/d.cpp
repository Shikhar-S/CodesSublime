#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;
int main(){
	int x,y;
	cin>>x>>y;
	int arr[x];
	int req[x];
	
	for(int i=0;i<x;i++)
		cin>>req[i];
	for(int i=0;i<x;i++)
		cin>>arr[i];
	bool flag=true;
	int m=-1;
	while(flag)
	{
		vector<int> v;
		m=INT_MAX;
		for(int i=0;i<x;i++)
			m=min(m,arr[i]/req[i]);
		for(int i=0;i<x;i++)
		{
			if((arr[i]/req[i])==m)
			{
				v.push_back(i);
			}
		}
		int l=v.size();
		for(int i=0;i<l;i++)
		{
			int j=v[i];
			int inc=(m+1)*req[j]-arr[j];
			if (y>=inc)
			{
				y-=inc;
				arr[j]=(req[j]*(m+1));
			}
			else 
				flag=false;
		}	
	}
	cout<<m<<endl;
	
}