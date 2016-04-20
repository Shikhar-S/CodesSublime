#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		int x;
		for(int i=0;i<n;i++){
			
			cin>>x;
			arr[i]=arr[i]-x;
		}
		int count[100001]={0};
		for(int i=0;i<(k+m);i++)
		{
			cin>>x;
			count[x]++;
		}
		int ans=0;
		
		for(int i=0;i<n;i++){
			for(int j=arr[i];j>0;j--){
				if(count[j]){
					count[j]--;
					arr[i]=arr[i]-j;
					break;
				}
			}
			ans+=arr[i];
		}
		cout<<ans<<endl;
	}
}