//
//  D.c
//  test
//
//  Created by Shikhar  on 25/11/15.
//  Copyright (c) 2015 Shikhar . All rights reserved.
//
#include <stdio.h>
typedef struct
{
    int a; // a is the node
    int b;  // b is the steps to reach this node from 0
}Q;
int n,f=-1,r=-1;

int min(int a,int b)
{
    return a<b?a:b;
}
void bfs(int arr[][n+1],int visited[],Q q[])
{
    int i;
    f++;
    while(r<f)
    {
        r++;
        Q temp=q[r];
        
      //printf("%d %d\n",temp.a,temp.b);
        //visited[temp.a]=1;
       // printf("%d %d\n",r,f);
        int x=temp.a;
        for(i=0;i<=n;i++)
        {
            if(arr[x][i] && (!visited[i] || visited[i]>temp.b+1))
            {
                //printf("%d \n",i);
                f++;
                q[f].a=i;
                q[f].b=temp.b+1;
                visited[i]=temp.b+1;
            }
        }
       /*for (int i=0; i<=n; i++) {
            printf("%d ",visited[i]);
        }
        printf("\n");*/
    }
    
}
int main()
{
    int t;
    scanf("%d",&t);
    
    while(t--)
    {
        
        scanf("%d",&n);
        int arr[n+1][n+1];
        int visited[n+1];
        int i,j;
        Q q[n*4];
        for(i=0;i<=n;i++)
        {
            q[i].a=0;
            q[i].b=0;
            visited[i]=0;
            for(j=0;j<=n;j++)
                arr[i][j]=0;
        }
        for(i=0;i<n;i++)
        {
            int x;
            scanf("%d",&x);
            
            if(i+x>=0 && i+x<=n)
            {
                arr[i][i+x]=1;
            }
                arr[i][i+1]=1;
        }
       /* for (int i=0; i<=n; i++) {
            for (int j=0; j<=n; j++) {
                printf("%d ",arr[i][j]);
                
            }
            printf("\n");
        }*/
        f=-1;r=-1;
        bfs(arr,visited,q);
        int ans=visited[n];
        if(ans!=0)
        printf("%d\n",ans);
        else
            printf("Fail Bibek\n");
    }
    return 0;
}