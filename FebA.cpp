#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	bool arr[n+1];
	for(int i=0;i<=n;i++)
		arr[i]=false;
	for(int i=0;i<n;i++)
	{
		int x;cin>>x;
		arr[x]=true;
	}
	for(int i=0;i<=n;i++)
	{
		if(!arr[i])
			cout<<i<<" ";
	}
}