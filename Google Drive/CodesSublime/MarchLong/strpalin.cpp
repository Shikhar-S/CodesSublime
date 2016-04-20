#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	char a[1001];
	char b[1001];
	int n;cin>>n;
	while(n--)
	{
		cin>>a>>b;
		int fr[27];
		for(int i=0;i<27;i++)
			fr[i]=0;
		int t=strlen(a);
		for(int i=0;i<t;i++)
			fr[a[i]-'a']++;
		int i;
		t=strlen(b);
		for (i = 0; i < t; ++i)
		{
			if(fr[b[i]-'a'])
			{
				cout<<"Yes\n";
				break;
			}
		}
		if (i>=t)
		{				
			cout<<"No\n";
		}
	}
	
}