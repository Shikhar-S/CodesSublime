#include <iostream>
#include <cstring>
#include <climits>
#define max 10000001
using namespace std;
typedef long long int ll;
int *p;
bool *visited;
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
    visited=new bool[max];
    p=new int[max];
	for(int i=0;i<max;i++)
        {
        	p[i]=-1;
        	visited[i]=false;
        }
    p[1]=1;visited[1]=true;

    for(int i=2;i<max;i+=1)
    {
    	if(!visited[i])
        {
            for(int j=1;j*i<max;j++)
            {
                if(!visited[j*i])
                {
                    visited[j*i]=true;
                    p[j*i]=i;
                }
            }
        }
    }
   
    int t;
    fastscan(t); 
    while(t--)
    {
        int n;
        fastscan(n);
        
        ll c=n;
        double ans=1;

        while(c>1)
        {
            ll loop=p[c];
            while(c%loop==0)
            {
                loop=loop*p[c];
            }
            loop/=p[c];
            ll temp=c;
            c=c/loop;
            ans*=((double)loop*loop*p[temp]+1)/((double)p[temp]+1);

        }
        printf("%lld\n",(ll)ans);
    }
}






