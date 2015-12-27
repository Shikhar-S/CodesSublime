//
//  D.c
//  test
//
//  Created by Shikhar  on 25/11/15.
//  Copyright (c) 2015 Shikhar . All rights reserved.
//
#include <stdio.h>
#include <string.h>
int main()
{
    int t,i;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        
        scanf("%d",&n);
        int arr[n+1];
        int ans[n+1];
        for(int i=1;i<=n;i++)
        {
            char ch[51];
            scanf("%s",ch);
            ans[i]=0;
            arr[i]=strlen(ch);
            //printf("%d ",arr[i]);
        }
        
        
        ans[0]=0;
        for(i=1;i<=n;i++)
        {
            
            int j=i;
            int k=i;
            int temp=0;
            while(j<n && arr[j]==arr[j+1])
            {
                temp+=1;
                // ans[j]=ans[k-1]+temp;
                j++;
            }
            temp+=1;
            i=j;
            ans[i]=ans[k-1];
            ans[i]+=temp;
            ans[i]+=ans[k-1];
        }
        printf("%d\n",ans[n]);
    }
    return 0;
}