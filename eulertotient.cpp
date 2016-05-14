#include <iostream>
using namespace std;
int phi[1000001];
int main(){
	int t;
	cin>>t;
	for(int i=1;i<1000001;i++)
		phi[i]=i;
	for(int i=2;i<1000001;i++){
		if(phi[i]==i)
		{
			for(int j=i;j<1000001;j+=i){
				phi[j]=(i-1)*(phi[j]/i);
			}
		}
	}
	int i=1;
	while(t--){
		int a,b;
		cin>>a>>b;
		if(phi[a]>phi[b]){
			cout<<"Case "<<i<<": Shibli took it"<<endl;
		}
		else
			cout<<"Case "<<i<<": Swapnil lost it"<<endl;
		i++;
			

	}
}