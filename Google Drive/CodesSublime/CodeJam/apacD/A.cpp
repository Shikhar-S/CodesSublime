#include <iostream>
#include <vector>
#define MAX 10000
using namespace std;
int r,c;
int getPos(int i,int j)
{
    if(i>=r || j>=c || i<0 || j<0)return -1;
    
    return c*(i)+j;
}
void dfs(vector<int> lst[],bool visited[],int x,bool on[])
{
    if (visited[x])
    {
        return;
    }
    else
    {
        visited[x]=true;
        int n=lst[x].size();
        for(int i=0;i<n;i++)
        {
            if (!visited[lst[x][i]] && on[lst[x][i]])
            {
                dfs(lst,visited,lst[x][i],on);
            }
        }
    }
    
}
int main()
{
    int t;cin>>t;
    for(int tt=1;tt<=t;tt++)
    {
    	vector<int> lst[MAX];
    	bool on[MAX]={false};
        cin>>r>>c;
        for(int i=0;i<r;i++)
        {

            for(int j=0;j<c;j++)
            {
                char ch;cin>>ch;
                if(ch=='1')
                on[getPos(i,j)]=true;
            }
        }
        for(int i=0;i<r*c;i++)
	    {
	        // cout<<i<<" ";
	        if(i-c>=0)//up
	        {
	            lst[i].push_back(i-c);
	            //lst[i-c].push_back(i);
	        }
	        if(i>0 && ((i-1)/c)==(i/c))//left
	        {
	            lst[i].push_back(i-1);
	            //lst[i-1].push_back(i);
	        }
	        if(i<r*c-1 && ((i+1)/c)==(i/c))//right
	        {
	            lst[i].push_back(i+1);
	            //lst[i+1].push_back(i);
	        }
	        if ( i+c<r*c)//down
	        {
	            //lst[i+c].push_back(i);
	            lst[i].push_back(i+c);
	        }
	    }
	    
        int n;cin>>n;
        cout<<"Case #"<<tt<<":\n";
        while(n--)
        {
            char ch;cin>>ch;
            if(ch=='Q')
            {
                int ans=0;
                bool visited[MAX]={false};
                for(int i=0;i<r*c;i++)
                {
                    if(!visited[i] && on[i])
                    {
                        dfs(lst,visited,i,on);
                        ans++;

                    }
                }
                
                cout<<ans<<endl;
            }
            else if(ch=='M')
            {
                int x,y,val;
                cin>>x>>y>>val;
                on[getPos(x,y)]=val;
            }
        }
        
        
    }
}