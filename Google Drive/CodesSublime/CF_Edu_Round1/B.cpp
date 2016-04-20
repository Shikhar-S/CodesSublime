#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	sort(arr,arr+n);
	int i=0,j=n-1;
	int ans[n];
	int c=0;
	while(i<=j)
	{
		ans[c++]=arr[i++];
		ans[c++]=arr[j--];
	}
	for(int i=0;i<n;i++)
		cout<<ans[i]<<" ";
	cout<<endl;
}