#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int main()
{
	int t;cin>>t;
	while(t--)
	{
		int n,k;cin>>n>>k;
		int arr[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];
		sort(arr,arr+n);
		ll sum=0;
		for(int i=k;i<n-k;i++)
			sum+=arr[i];
		double ans=(double)sum/(n-2*k);
		printf("%.6lf\n",ans);

	}
}