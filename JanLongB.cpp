#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;
bool prime[10001];
int main(){
	for(int i=0;i<10001;i++)
		prime[i]=true;
	prime[0]=false;
	prime[1]=false;
	for(int i=2;i<10001;i++)
	{
		if(prime[i]){
			for(int j=i*2;j<10001;j+=i){
				prime[j]=false;
			}
		}
	}
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];
		int ans=INT_MAX;
		for(int i=2;i<10001;i++){
			
			if(prime[i]){
				int k=0;
				int temp=0;
				for(int j=0;j<n;j++){
					int l=(arr[j]%i==0)?arr[j]/i:(arr[j]/i)+1;
					if(l>=k){
						k=l;
						temp+=i*l-arr[j];
					}
					else{
						temp+=i*k-arr[j];
					}
				}
				ans=min(temp,ans);
			}
		}
		cout<<ans<<endl;
	}
}