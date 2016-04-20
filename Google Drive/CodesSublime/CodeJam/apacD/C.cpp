#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
typedef long long ll;
ll calc(ll x)
{
    
    return (x*(x+1))/2;
    
}
int main()
{
    int n,k;cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    vector<int> v[300002];
    for(int i=0;i<k;i++)
    {
        int x,y;cin>>x>>y;
        v[x].push_back(i);
        v[y].push_back(i);
    }
    set<int> st;
    int i=0,j=0;
    ll ans=0;
    /*4 2
     1 3 2 4
     3 2
     2 4*/
    for(int l=0;l<n;l++)
    {
        
        if(v[arr[l]].size()!=0)
        {
            int len=v[arr[l]].size();
            for(int x=0;x<len;x++)
            {
                int num=v[arr[l]].at(x);
                set<int>:: iterator it=st.find(num);
                if(it==st.end())
                    st.insert(num);
                else
                {
                    
                    
                    ans+=calc(j-i);
                    
                    cout<<i<<" "<<j<<" "<<calc(j-i)<<" \n";
                    i=l;
                    j=l;
                    st.clear();
                }
                
            }
        }
        j++;
    }
    cout<<i<<" "<<j<<" "<<calc(j-i)<<" \n";
    ans+=calc(j-i);
    cout<<ans<<endl;
}