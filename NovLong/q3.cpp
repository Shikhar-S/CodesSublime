//
//  q3.cpp
//  test
//
//  Created by Shikhar  on 11/11/15.
//  Copyright (c) 2015 Shikhar . All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int *arr;
void fastscan(int &x)
    {
        bool neg=false;
        register int c;
        x =0;
        c=getchar();
        if(c=='-')
        {
            neg = true;
            c=getchar();
        }
        for(;(c>47 && c<58);c=getchar())
            x = (x<<1) + (x<<3) +c -48;
        if(neg)
            x *=-1;
    }

int main()
{
    int t;
    fastscan(t);

    while(t--)
    {
        int n;fastscan(n);
        arr=new int[n+1];
        for (int i=0; i<=n; i++) {
            arr[i]=1;
        }
       // memset(arr,1,sizeof(arr));
        for(int i=2;i<=n;i++)
        {
            if(n%i==0)
            {
                for(int j=i;j<=n;j+=i)
                {
                    arr[j]=i;
                }
            }
        }
        long long int ans=0;
        for(int i=1;i<=n;i++)
        {
           // cout<<arr[i]<<" ";
            ans+=(n/arr[i]);
        }
        printf("%lld\n",ans);
    }
}