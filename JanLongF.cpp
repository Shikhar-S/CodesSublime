#include <iostream>
#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;
typedef long long ll;
double rs[1002][1000];
double dollar[1002][1000];
ll selling[1000][1000];
ll buying[1000][1000];

double max4(double a,double b,double c,double d){
	double ans=0;
	ans=max(a,ans);
	ans=max(b,ans);
	ans=max(c,ans);
	ans=max(d,ans);
	return ans;
}
int main(){
	int n,m;
	double d;
	cin>>n>>m>>d;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			dollar[i+1][j]=0;
			rs[i+1][j]=d;
			cin>>selling[i][j];
			cin>>buying[i][j];
		}
	}
	for(int i=0;i<m;i++){
		rs[0][i]=0;
		rs[n+1][i]=0;
		dollar[0][i]=0;
		dollar[n+1][i]=0;
	}
	for(int i=1;i<=n;i++){
		dollar[i][0]=rs[i][0]/selling[i-1][0];
	}
	double ans=d;
	bool flag=true;
	for(int j=1;j<m;j++){
		for(int i=1;i<=n;i++){
			rs[i][j]=max4(rs[i-1][j-1],rs[i][j-1],rs[i+1][j-1],buying[i-1][j]*dollar[i][j-1]);
			dollar[i][j]=max4(dollar[i-1][j-1],dollar[i][j-1],dollar[i+1][j-1],rs[i][j-1]/selling[i-1][j]);
			ans=max(ans,rs[i][j]);
			if(ans>1000000000000000000)
			{
				cout<<"Quintillionnaire"<<endl;
				i=n+1;j=m+1;
				flag=false;
			}
		}
	}
	if(flag)
	printf("%.10lf\n",ans);
}