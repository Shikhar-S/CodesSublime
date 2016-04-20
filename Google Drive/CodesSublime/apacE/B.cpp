#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int n,k;
        cin>>n>>k;
        int a[n],b[n],c[n],d[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(int i=0;i<n;i++)
        {
            cin>>b[i];
        }
        for(int i=0;i<n;i++)
        {
            cin>>c[i];
        }
        for(int i=0;i<n;i++)
        {
            cin>>d[i];
        }
        int sec_third[n*n];
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                sec_third[cnt++]=c[i]^d[j];
                //cout<<sec_third[cnt-1]<<" ";
            }
        }
        sort(sec_third,sec_third+(cnt));
       /* cout<<endl;
        for (int i = 0; i < cnt; ++i)
        {
            cout<<sec_third[i]<<" ";
        }
        cout<<endl;*/
        ll ans=0;
        for(int i=0;i<n;i++)
        {
            
            for(int j=0;j<n;j++)
            {
                int x=a[i]^b[j]^k;
                //cout<<x<<endl;
                if(sec_third[cnt-1]>=x && sec_third[0]<=x)
                {
                    ll xx=(upper_bound(sec_third,sec_third+cnt,x)-sec_third);
                    ll yy=(lower_bound(sec_third,sec_third+cnt,x)-sec_third);
                    ans+=(xx-yy);
                   // cout<<xx<<" "<<yy<<"\n";
                    
                }
                
            }
            
        }
        cout<<"Case #"<<i<<": "<<ans<<"\n";
        
    }
}