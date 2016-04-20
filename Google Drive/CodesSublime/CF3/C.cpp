#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int arr[100005];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        
        cin>>arr[i];
    }
    int ans=0;
    vector<int> answer;
    sort(arr,arr+n);
    int i;
    int k=1;
    while(k!=arr[0])
    {
        if(ans+k>m)
            break;
        answer.push_back(k);
        k++;
        ans+=k-1;
    }
    for(i=0;i<n-1;i++)
    {
        if(arr[i]!=arr[i+1]-1)
        {
            int k=arr[i]+1;
            while(k!=arr[i+1])
            {
                
                if(ans+k>m)
                    break;
                answer.push_back(k);
                ans+=k;
                k++;
                    
            }
            if(k!=arr[i+1])
                break;
        }
    }
        if(i==n-1 && ans<m)
        {
            int k=arr[n-1]+1;
            while(ans<m)
            {
                if(ans+k>m)
                    break;
                answer.push_back(k);
                k++;
                ans+=k;
            }
           // ans+=k;
            
        }
        
    
    cout<<answer.size()<<endl;
    int sz=answer.size();
    for(int i=0;i<sz;i++)
        cout<<answer[i]<<" ";
    cout<<endl;
}