#include <iostream>
#include <string>
#include <set>
using namespace std;
int main()
{

	int n;
	while(scanf("%d",&n)==1)
	{
		set<string> st;
		string a;
		for(int i=0;i<n;i++)
		{
			cin>>a;
			set<string>::iterator it=st.find(a);
			if (it==st.end())
			{
				st.insert(a);
			}
			else
			{
				st.erase(it);
			}
		}
		if (!st.empty())
		{
			cout<<"first player\n";
		}
		else
		{
			cout<<"second player\n";
		}

	}
	
}