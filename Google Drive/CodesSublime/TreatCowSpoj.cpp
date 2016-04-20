#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int ll;
int main(){
	ll n;
	cin>>n;
	ll arr[n];
	ll sum[n+1];
	sum[n]=0;
	cin>>arr[0];
	sum[0]=arr[0];
	ll dp[n][n];
	dp[0][0]=arr[0];
	for(ll i=1;i<n;i++){
		cin>>arr[i];
		dp[i][i]=arr[i];
		sum[i]=sum[i-1]+arr[i];
	}
		for(ll i=n-1;i>=1;i--){
		ll r=0;
		ll c=n-i;
		for(ll j=0;j<i;j++){
			dp[r][c]=max(arr[r]+dp[r+1][c]+sum[c]-sum[r],dp[r][c-1]+arr[c]+sum[c-1]-sum[r-1>=0?r-1:n]);
			r++;c++;
		}
	}
	cout<<dp[0][n-1]<<endl;
}