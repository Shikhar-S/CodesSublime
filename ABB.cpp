#include <iostream>
#include <string>
using namespace std;
int main()
{
	int t;cin>>t;
	while(t--)
	{
		string x;cin>>x;
		int n=x.length();
		int A_cnt=0,B_cnt=0;
		for(int i=0;i<n;i++)
			int k=(x[i]=='A')?A_cnt++:B_cnt++;
		if(A_cnt==2)
		{
			cout<<"A\n";
			continue;
		}
		if(B_cnt==2)
		{
			cout<<"B\n";
			continue;
		}
		A_cnt=0;B_cnt=0;
		int i;
		for(i=0;i<n;i++)
		{
			if (x[i]=='A')
			{
				A_cnt++;
				B_cnt=0;
			}
			else
			{
				B_cnt++;
				A_cnt=0;
			}
			if (A_cnt==2 && ((i<n && x[i+1]=='B') || (i==n-1)))
			{
				string k=x.substr(0,i-1)+x.substr(i,n-i);
				cout<<k<<endl;
				break;
			}
			else if(B_cnt==2 && ((i<n && x[i+1]=='A') || (i==n-1)))
			{
				string k=x.substr(0,i-1)+x.substr(i,n-i);
				cout<<k<<endl;
				break;
			}
		}
		if (i!=n)
		{
			continue;
		}
		cout<<-1<<endl;
	}
}