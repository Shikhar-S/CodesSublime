#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int cnt=0;
        char str[1000005];
        cin>>str;
        int n=strlen(str);
        if(n==1)
            cout<<"NO\n";
        
        else if(n%2==0)
        {
            int k=n/2;
            int i;
            for(i=0;i<k;i++)
            {
                if(str[i]!=str[k+i])
                {
                    cout<<"NO\n";
                    break;
                }
            }
            if(i>=k)
            {
                cout<<"YES\n";
            }
        }
        else
        {
            int i=0,j=(n/2+1);
            int f=1;
            cnt=0;
            for(i=0;i<=n/2 && j<n;)
            {
                
                if(str[i]!=str[j])
                {
                    i++;
                    cnt++;
                    if(cnt>1)
	                {
	                    f=0;
	                    break;
	                }
                }
                else
                {
                    i++;j++;
                }
            }
            if(f==0)
            {
                i=0,j=n/2;
                f=1;
                cnt=0;
                for(i=0;i<n/2 && j<n;)
                {
                    
                    if(str[i]!=str[j])
                    {
                        j++;
                        cnt++;
                        if(cnt>1)
	                    {
	                        f=0;
	                        break;
	                    }
                    }
                    else
                    {
                        i++;j++;
                    }
                }
            }
            if(f)
            {
                cout<<"YES\n";
            }
            else
            {
                cout<<"NO\n";
            }
        }
    }
}