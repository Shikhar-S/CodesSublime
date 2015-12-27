#include<stdio.h>
#define max 1000001
int n;
int getIndex(int arr[][n],int visited[])
{
    int min=max;int p=-1;
    int i,j;
    for(i=0;i<n;i++)
    {
        if(visited[i])
        {
            for(j=0;j<n;j++)
            {
                if(!visited[j] && arr[i][j] && arr[i][j]<min)
                {
                    min=arr[i][j];
                    p=j;
                }
            }
        }
    }
    return p;
}
void prim(int arr[][n],int visited[],int ans[])
{
    int i,j,t=0;
    for (i = 0; i < n; ++i)
    {
        int index=getIndex(arr,visited);
        if(index!=-1)
        {
            for(j=0;j<n;j++)
            {
                if(visited[j] && arr[j][index] && arr[j][index]<ans[index])
                {
                    ans[index]=arr[j][index];
                    t=j;
                }
            }
            visited[index]=1;
        }
    }
}
int main()
{
    int m,i,j,x,y,z;
    scanf("%d %d",&n,&m);
    int visited[n];
    int ans[n];
    int arr[n][n];
    for(i=0;i<n;i++)
    {
        ans[i]=max;
        visited[i]=0;
        for(j=0;j<n;j++)
            arr[i][j]=0;
    }
    for (i = 0; i < m; ++i)
    {
        scanf("%d %d %d",&x,&y,&z);
        arr[x-1][y-1]=z;
        arr[y-1][x-1]=z;
    }
    visited[0]=1;
    ans[0]=0;
    prim(arr,visited,ans);
    int sum=0;
    for (i = 0; i < n; ++i)
    {
        //printf("%d ",ans[i]);
        sum+=ans[i];
    }
    printf("%d\n",sum);
}