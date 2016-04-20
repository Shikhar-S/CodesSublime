#include <iostream>
#define mod 1000000007
typedef long long ll;
using namespace std;
ll arr[100001];
ll sum[100001];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		n++;
		cin>>arr[0];
		ll factor=1;
		sum[0]=arr[0]*2;
		for(int i=1;i<n;i++)
			{
				factor=(factor*2)%mod;
				cin>>arr[i];
				sum[i]=(sum[i-1]+(factor*arr[i])%mod)%mod;
			}
		ll ans=0;
		for(int i=1;i<n;i++){
			ans=((ans*2)%mod+(arr[i]*sum[i-1])%mod)%mod;
		}
		
		cout<<(ans==0?arr[0]/2:ans)<<endl;
	}
}