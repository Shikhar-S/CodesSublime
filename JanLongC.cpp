#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int r,c;
		cin>>r>>c;
		int top=0,bottom=0,right=0,left=c-1;
		bool top_set=false;
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				char ch;cin>>ch;
				if(ch=='*'){
					bottom=i;
					if(!top_set){
						top_set=true;
						top=i;
					}
					right=max(right,j);
					left=min(left,j);
				}
			}
		}
		int centre_r=(top+bottom)/2;
		int centre_c=(left+right)/2;
		int ans=INT_MIN;
		ans=max(centre_r-top,ans);
		ans=max(bottom-centre_r,ans);
		ans=max(right-centre_c,ans);
		ans=max(centre_c-left,ans);
		if(!top_set)
			cout<<0<<endl;
		else
		cout<<ans+1<<endl;
	}
}