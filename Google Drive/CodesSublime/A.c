#include <stdio.h>
int n;
int dfs(int x,int visited[],int arr[][n],int color[])
{
    int i;
    visited[x]=1;
    int ans=1;
    for(i=0;i<n;i++)
    {
        if(arr[x][i] && !visited[i])
        {
                color[i]=!(color[x]);
                ans=dfs(i,visited,arr,color);
                if(ans==0)return ans;
        }
        else if(arr[x][i] && visited[i])
        {
            if(color[i]==(!color[x]))
                ans=1;
            else 
                return 0;
        }
            
    }
    return ans;

}
int main()
{
    int t;
    scanf("%d ",&t);
    while(t--)
    {
        int e,i,j;
        scanf("%d %d",&n,&e);
        int arr[n][n];
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
                arr[i][j]=0;
        }
        for(i=0;i<n;i++)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            arr[x][y]=1;
            arr[y][x]=1;
        }
        int visited[n];
        int color[n];
        for(i=0;i<n;i++)
        {
            color[i]=-1;
            visited[i]=0;
        }
        int ans=1;
        for(i=0;i<n;i++)
        {
            if(!visited[i] && ans)
            {
                color[i]=1;
                ans=dfs(i,visited,arr,color);
            }
                
        }
        
        if(!ans)
            printf("Trick\n");
        else
            printf("Treat\n");
    }
}