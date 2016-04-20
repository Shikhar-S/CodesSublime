#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;
int grundyGenerate(int arr[],bool check[],int n)
{
    int xo=0;
    for (int i = 0; i < n; ++i)
    {
        if(check[i])
            xo=xo^arr[i];
    }
    if(xo==0)
    {
        return 1;
    }
    else
    {
        int m=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(check[i])
            {
                check[i]=false;
                int a=grundyGenerate(arr,check,n);
                m=min(a,m);
                check[i]=true;
            }
            
        }
        return m+1;
    }
}
int main()
{
    int arr[501];
    int grundy[501];
    for(int i=0;i<501;i++)
    	grundy[i]=0;
    int t;
    cin>>t;
    bool check[501]={true};
    while(t--)
    {
        int n;
        cin>>n;
        int t=0;
        for(int i=0;i<n;i++)
            {
            	cin>>arr[i];
            	t=t^arr[i];
            }
        if(t==0)
        {
        	cout<<"First\n";
        	continue;
        }
        int xr=0;
        for(int i=0;i<n;i++)
        {
        	//check[i]=false;
            grundy[i]=grundyGenerate(arr,check,n);
            //check[i]=true;
            xr=xr^grundy[i];
        }
        
        if(xr)
            cout<<"Second\n";
        else
            cout<<"First\n";
    }
}