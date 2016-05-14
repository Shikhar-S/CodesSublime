#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
typedef long long ll;
int main()
{
	int n;cin>>n;
	while(n!=0)
	{
		int arr[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];
		ll ans=0;
		stack<int> st;
		int i;
		for(i=0;i<n;)
		{
			if (st.empty() || arr[st.top()]<arr[i])
			{
				st.push(i);
				i++;
			}
			else
			{
				int t=st.top();
				st.pop();
				ll cal=(ll)arr[t]*(st.empty()?i:i-st.top()-1);
				ans=max(ans,cal);
			}
		}

		while(!st.empty())
		{
				int t=st.top();
				st.pop();
				ll cal=(ll)arr[t]*(st.empty()?i:i-st.top()-1);
				ans=max(ans,cal);
		}

		cout<<ans<<"\n";
		cin>>n;
	}

}