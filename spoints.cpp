//http://www.spoj.com/problems/SPOINTS/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;
struct point{
    int x;int y;
};
point a[10000];
point b[10000];
point anchor;
bool dist(point o,point a,point b)
{
    int OB=(o.x-b.x)*(o.x-b.x)+(o.y-b.y)*(o.y-b.y);
    int OA=(o.x-a.x)*(o.x-a.x)+(o.y-a.y)*(o.y-a.y);
    return (OA<=OB);
}
bool orientationLeft(point o,point a,point b)
{
    int t=((a.x-o.x)*(b.y-o.y))-((a.y-o.y)*(b.x-o.x));
    if(t==0)
        return dist(o,a,b);
    else
        return (t)>0;
}
bool comp(point a,point b)
{
    return orientationLeft(anchor,a,b);
}
void grahamScan(point x[],int n,vector<point> &ans)
{
    
    anchor=x[0];
    int min_idx=0;
    for(int i=0;i<n;i++)
    {
        if(x[i].y<anchor.y || (x[i].y==anchor.y && x[i].x<anchor.x))
        {
            anchor=x[i];
            min_idx=i;
        }
    }
        swap(x[min_idx],x[0]);
    sort(x+1,x+n,comp);

    ans.push_back(x[0]);
    if(n==1) return;
    ans.push_back(x[1]);
    int k=ans.size();
    for(int i=2;i<n;i++)
    {
         while(k>=2 && !orientationLeft(ans[k-2],ans[k-1],x[i]))
            k--;
        ans.resize(k);
        ans.push_back(x[i]);
        k++;
    }
    ans.resize(k);
}
bool onSegment(point p, point q, point r)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
       return true;
 
    return false;
}
bool intersect(point segA[],point segB[])
{
    double slope=(segA[1].y-segA[0].y)/(double)(segA[1].x-segA[0].x);
    double m1=(segB[0].y-segA[0].y)-(slope)*(segB[0].x-segA[0].x);
    double m2=(segB[1].y-segA[0].y)-(slope)*(segB[1].x-segA[0].x);
    return m1*m2<0 || (m1*m2==0 && (onSegment(segA[0],segB[0],segA[1]) || onSegment(segA[0],segB[1],segA[1])));
}

bool canPartition(vector<point> &a,vector<point> &b,int cur)
{
    int next=(cur+1)%(a.size());
    if(a.size()==1)return false;
    point direction={a[cur].x-a[next].x,a[cur].y-a[next].y};
    point normal={-direction.y,direction.x};
    double x_dir=normal.x/(double)(sqrt(normal.x*normal.x+normal.y*normal.y));
    double y_dir=normal.y/(double)(sqrt(normal.x*normal.x+normal.y*normal.y));
    int n_b=b.size();
    double min_b=INT_MAX;
    double max_b=INT_MIN;
    for(int i=0;i<n_b;i++)
    {
        double project=x_dir*b[i].x+y_dir*b[i].y;
        min_b=min(min_b,project);
        max_b=max(max_b,project);
    }
    int n_a=a.size();
    double min_a=INT_MAX;
    double max_a=INT_MIN;
    for(int i=0;i<n_a;i++)
    {
        double project=x_dir*a[i].x+y_dir*a[i].y;
        min_a=min(min_a,project);
        max_a=max(max_a,project);
    }
    if((min_a<min_b && max_a<min_b)||(min_b<min_a && max_b<min_a))
        return true;
    else
        return false;
}
int main()
{
    int d,p;
    
    do{
        cin>>d>>p;
        bool flag=false;
        if(d==0 && p==0)break;
        if(d==1 && p==1) flag=true;

        int idx=0,ipx=0;
        for(int i=0;i<d;i++)
        {
            int x1,y1;
            cin>>x1>>y1;
            a[idx++]=(point){x1,y1};
        }
        for(int i=0;i<p;i++)
        {
            int x1,y1;
            cin>>x1>>y1;
            b[ipx++]=(point){x1,y1};
        }
        
        if(!flag && (d>=3 || p>=3))
        {
          vector<point> d_convex;
            grahamScan(a,d,d_convex);
            vector<point> p_convex;
            grahamScan(b,p,p_convex);
            
            int n_d=d_convex.size();
            int n_p=p_convex.size();
            for(int i=0;i<n_d && !flag;i++)
            {
                flag=canPartition(d_convex,p_convex,i);
            }
            for(int i=0;i<n_p && !flag;i++)
            {
                flag=canPartition(p_convex,d_convex,i);
            }  
        }
        if(d==1 && p==2) flag=!(onSegment(b[0],a[0],b[1]));
        if(d==2 && p==1) flag=!(onSegment(a[0],b[0],a[1]));
        if(d==2 && p==2) flag=!(intersect(a,b));
        
        if(flag)
            cout<<"YES\n";
        else
            cout<<"NO\n";
        
    
    }while(1);
}