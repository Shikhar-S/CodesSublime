#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int arr[50005];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> v;
		for(int i=0;i<n;i++)
			cin>>arr[i];
		arr[n]=-1;
		sort(arr,arr+n);
		int ans=0;
		for(int i=0;i<n;i++){
			if(arr[i]==arr[i+1]){
				ans++;
				
			}
			else
			{
				v.push_back(ans+1);
				ans=0;
			}
		}
		sort(v.begin(),v.end());
		ans=max(v[v.size()-1],(n+1)/2);
		cout<<ans<<"\n";
	}
}