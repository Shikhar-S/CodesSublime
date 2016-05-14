#include <iostream>
#include <set>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;
int freq[5001]={0};
int cnt[5001][5001];
int main()
{
	int n;cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cnt[i][j]=0;
		}
	}
    
    int m=-1;
    for(int i=0;i<n;i++)
    {
        int l=INT_MIN;
        for(int j=i;j<n;j++)
        {
            cnt[i][arr[j]]++;
            if (cnt[i][arr[j]] > l || (cnt[i][arr[j]]==l && arr[j]<m))
            {
                l=cnt[i][arr[j]];
                m=arr[j];
                
            }
            freq[m]++;
        }
    }
	for(int i=1;i<=n;i++)
		cout<<freq[i]<<" ";
	cout<<endl;
}