#include <iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		if(n<7)
			cout<<"-1\n";
		else
		{
			int i;
			cout<<n<<endl;
			int k=(n+1)/2;
			if(n%2!=0)
			{for( i=1;i<n-1;i++)
			cout<<i<<" "<<i+1<<endl;
			cout<<n-1<<" "<<"1"<<endl;
			cout<<k+1<<" "<<n<<endl;
		    cout<<k<<endl;
		}
			else
				{
					for(i=1;i<n-2;i++)
			cout<<i<<" "<<i+1<<endl;
			cout<<n-2<<" "<<"1"<<endl;
			cout<<2<<" "<<n-1<<endl;
			cout<<k<<" "<<n<<endl;
			cout<<(n-1)/2<<endl;
		}

			
		}

	}
}