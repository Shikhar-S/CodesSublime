#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;
int main(){
	int n;
	cin>>n;
	do{

		int arr[n+1];
		for(int i=0;i<n+1;i++)
			arr[i]=0;
		string x;
		cin>>x;
		int k=0;
		for(int i=2;i<=n;i++){

			if(x[i-1]==x[k])
			{
				arr[i]=k+1;
				k++;
			}
			else
			{
				if(k!=0){
					k=arr[k-1];
					i--;
				}
				else{
					arr[i]=0;
				}
			}
		}
		/*for(int i=1;i<=n;i++)
			cout<<arr[i]<<" ";*/
		k=0;
		char ch;
		cin>>ch;
		int i=0;
		do{
			while(true){
				if(ch==x[k]){
					if(k==n-1){
					cout<<i-k<<endl;
					k=arr[k+1];
					break;
					}
					else{
						k++;
						break;
					}
				}
				else{
					if(k==0){
						break;
					}
					else
					{
						k=arr[k-1];
					}
				}
			}
			
			i++;
		}while(scanf("%c",ch)!=EOF);
		n=ch-'0';
		cout<<endl;
	}while(n!=(int)'\n');
}