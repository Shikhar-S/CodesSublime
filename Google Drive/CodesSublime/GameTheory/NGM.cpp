#include <iostream>
using namespace std;
int main()
{
	int x;
	cin>>x;
	if(x%10==0)
		cout<<"2"<<endl;
	else
	{
		cout<<"1\n";
		cout<<x%10<<"\n";
	}
}