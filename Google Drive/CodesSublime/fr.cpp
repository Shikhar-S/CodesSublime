#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
	cin>>n>>m>>k;
	int d=max(n,m)-min(n,m);
	if(k>=d)
		cout<<"0\n";
	else
		cout<<d-k<<"\n";
	}
	
}