#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int main()
{
	int n,c;cin>>n>>c;
	int p[n];
	int t[n];
	for(int i=0;i<n;i++)
	{
		cin>>p[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>t[i];
	}
	ll a=0,b=0;
	ll a_t=0,b_t=0;
	for(int i=0;i<n;i++)
	{
		a_t+=t[i];
		a+=max(0,p[i]-(a_t*c));
	}
	for(int i=n-1;i>=0;i--)
	{
		b_t+=t[i];
		b+=max(0,p[i]-(b_t*c));
	}
	if(a>b)
		cout<<"Limak\n";
	else if(a<b)
		cout<<"Radewoosh\n";
	else
		cout<<"Tie\n";
}
