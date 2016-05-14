#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <set>
#include <stack>
#include <algorithm>
using namespace std;
int *arr;
stack<pair<int,int> > st;
vector<pair<int,int> > *v;
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
int dfs(int x,bool visited[],int num)
{
    st.push(make_pair(x,num));
    int m=x;
    while(!st.empty())
    {
        int top=st.top().first;
        num=st.top().second;
        st.pop();
        if(top>m)m=top;
        visited[top]=true;
        for(vector<pair<int,int> >::iterator iter=v[top].begin();iter!=v[top].end();iter++)
        {
            if(!visited[iter->first] && iter->second>=num)
                st.push(*iter);

        }

    }
    
    return m;
}
int main()
{
    int t;
    fastscan(t);
    while(t--)
    {
        int n,m;
        fastscan(n);
        fastscan(m);
        arr=new int[200001];
        v=new vector<pair<int,int> >[50001];
        for(int i=0;i<=200000;i++)
            arr[i]=0;
        for(int i=0;i<n;i++)
        {
            int x;
            fastscan(x);
            arr[x]++;
        }
        
        for(int i=0;i<m;i++)
        {
            int a,b,c;
            fastscan(a);
            fastscan(b);
            fastscan(c);
            v[b].push_back(make_pair(c,a));
            v[c].push_back(make_pair(b,a));
        }
        long long int ans=0;
        bool visited[200001];
        int c=0;
        for(int j=1;j<=200000 && c<n;j++)
        {

            if(arr[j]>0)
            {
            	c++;
                for(int i=0;i<=200000;i++)
                    visited[i]=false;
                int num=dfs(j,visited,0);
                ans=ans+((long long int)num*arr[j]);
                arr[j]=0;
            }
        }
        delete [] arr;
        delete [] v;
        printf("%lld\n",ans);
    }
}