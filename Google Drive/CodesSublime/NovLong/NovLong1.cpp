#include <iostream>
using namespace std;
typedef long long int ll;
ll hcf(ll n1,ll n2)
{
	ll tmp=0;
    while (n2 != 0) {
        tmp = n1;
        n1 = n2;
        n2 = tmp % n2;
    }
    return n1;

}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll x,y;
		cin>>x>>y;
		if(x!=0 && y!=0)
		{
			ll ans=hcf(x,y);
			if((max(x,y)/ans)==max(x,y))
				cout<<"Yes"<<endl;
			else
				cout<<"No "<<max(x,y)/ans<<endl;
		}
		else
		{
            if((x==0 && y!=0))
                cout<<"No 0"<<endl;
            
            else if(y==0 && x!=0 && x!=1)
                cout<<"No 1"<<endl;
            
            else if(x==1 && y==0)
                cout<<"Yes"<<endl;
            
            else cout<<"Yes"<<endl;
		}
		
	}	
}