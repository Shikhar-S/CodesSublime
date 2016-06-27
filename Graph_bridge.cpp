    #include <iostream>
    #include <algorithm>
    #include <vector>
    #include <climits>
    #include <utility>
    #include <map>
    #include <set>
    #define M 500500
    using namespace std;
    vector<int> graph[M];
    map< pair<int,int> , int > mp;
    bool visited[M]={false};
    int low[M]={INT_MAX};
    int disc[M]={INT_MAX};
    int parent[M]={0};
    int time_stamp=0;
    set<pair<int,int> > bridges;
    bool vis[M]={false};
    void tarjanBridge(int current)
    {
    	visited[current]=true;
    	time_stamp++;
    	low[current]=time_stamp;  //initialize current nodes discovery time and 
    	disc[current]=time_stamp;	//time of lowest disc in its subtree as current timestamp
    	int sz=graph[current].size();
    	for(int i=0;i<sz;i++)			//iterate for all children
    	{
    		int child=graph[current][i];	
    		if(!visited[child])			
    		{
    			parent[child]=current;		//used at end to avoid updating low value for parent
    			tarjanBridge(child);		//recurse
    			low[current]=min(low[current],low[child]);
    			pair<int,int> temp=make_pair(current,child);					//update low value of parent
    			if(low[child]>disc[current] && mp[temp] == 1)					
    				bridges.insert(make_pair(max(child,current),min(child,current)));
    		}
    		else if(child != parent[current])
    		{
    			low[current]=min(low[current],disc[child]);
    		}
    	}
    	
    }
    int count(int x)
    {
    	int ans=0;
    	for(int i=0;i<graph[x].size();i++)
    		if(bridges.find(make_pair(x,graph[x][i]))!=bridges.end() || bridges.find(make_pair(graph[x][i],x))!=bridges.end())
    			ans++;
    	return ans==1;
    }
    int main()
    {
    	int n,m;
    	cin>>n>>m;
    	int x,y;
    	for(int i=0;i<m;i++)
    	{
    		cin>>x>>y;
    		graph[x].push_back(y);
    		graph[y].push_back(x);
    		pair<int,int> temp=make_pair(x,y);
    		try{
    			
    			mp[temp]+=1;
    			
    		}
    		catch(...)
    		{
    			mp[temp]=1;
    		}
    		try{
    			temp=make_pair(y,x);
    			mp[temp]+=1;
    		}
    		catch(...)
    		{
    			mp[temp]=1;
    		}
    		
    	}
    	if(m==0)
    	{
    		cout<<((n<=2)?"YES\n":"NO\n");
    		return 0;
    	}
    	tarjanBridge(x);
    	int c=0;
    	/*for(set<pair<int,int> >::iterator it=bridges.begin();it!=bridges.end() && c<2;it++)
    	{
    		int fr=(*it).first;
    		cout<<fr<<endl;
    		c+=dfsAndRemove(fr);
    	}*/
    	bool flag=true;
    	for(set<pair<int,int> >::iterator it=bridges.begin();it!=bridges.end();it++)
    	{
    		c+=count(it->first);
    		c+=count(it->second);
    	}
    	if(c%2==1 || c>4)
    		flag=false;
    	if(!flag)
    		cout<<"NO\n";
    	else
    		cout<<"YES\n";
    } 