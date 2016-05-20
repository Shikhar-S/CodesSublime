// http://www.spoj.com/problems/DOORSPEN/
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
    //for(int i=0;i<ans.size();i++)
      //  cout<<ans[i].x<<" "<<ans[i].y<<endl;
    
}
bool canPartition(vector<point> &a,vector<point> &b,int cur)
{
    int next=(cur+1)%(a.size());
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
    int j=1;
    do{
        cin>>d>>p;
        if(d==0 && p==0)break;
        
        int idx=0,ipx=0;
        for(int i=0;i<d;i++)
        {
            int x1,y1,x2,y2;
            cin>>x1>>y1>>x2>>y2;
            a[idx++]=(point){x1,y1};
            a[idx++]=(point){x2,y2};
            a[idx++]=(point){x1,y2};
            a[idx++]=(point){x2,y1};
        }
        for(int i=0;i<p;i++)
        {
            int x1,y1,x2,y2;
            cin>>x1>>y1>>x2>>y2;
            b[ipx++]=(point){x1,y1};
            b[ipx++]=(point){x2,y2};
            b[ipx++]=(point){x1,y2};
            b[ipx++]=(point){x2,y1};
        }
        vector<point> d_convex;
        grahamScan(a,d*4,d_convex);
        vector<point> p_convex;
        grahamScan(b,p*4,p_convex);
        bool flag=false;
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
        if(flag)
            cout<<"Case "<<j<<": It is possible to separate the two groups of vendors."<<endl;
        else
            cout<<"Case "<<j<<": It is not possible to separate the two groups of vendors."<<endl;
        cout<<"\n";
        j++;
    }while(1);
}