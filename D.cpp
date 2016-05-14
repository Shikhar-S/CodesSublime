//
//  test.cpp
//  test
//
//  Created by Shikhar  on 28/03/16.
//  Copyright © 2016 Shikhar . All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define iOS ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;
struct data
{
    int l,r;
    int idx;
};
int BIT[200005];
int n;
void add(int idx,int val)
{
    for(;idx<=n;idx+=(idx&-idx))
    {
        BIT[idx]+=val;
    }
}
int get(int idx)
{
    int ans=0;
    
    for(;idx>0;idx-=(idx&-idx))
        ans+=BIT[idx];
    return ans;
    
}
bool comp(data &a,data &b)
{
    
    return a.l<b.l;
}
int binsrch(int arr[],int x)
{
    int l=0,r=n-1;
    while(l<=r)
    {
        int mid=l+(r-l)/2;
        if(arr[mid]==x)
            return mid;
        else if(arr[mid]>x)
        {
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    return -1;
}
int main()
{
    //iOS;
    cin>>n;
    data arr[n];
    int rt[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i].l>>arr[i].r;
        rt[i]=arr[i].r;
        arr[i].idx=i;
    }
    sort(arr,arr+n,comp);
    sort(rt,rt+n);
    int ans[n];
    //for(int i=0;i<n;i++)
      //  cout<<rt[i]<<" ";
    //printf("\n");
    for(int i=n-1;i>=0;i--)
    {
        int k=arr[i].r;
        int index=binsrch(rt,k)+1;
      //  cout<<index<<"<- index "<<arr[i].r<<"<-value \n";
        ans[arr[i].idx]=get(index);
        add(index,1);
    }
    for(int i=0;i<n;i++)
    {
        printf("%d\n",ans[i]);
    }
    
}