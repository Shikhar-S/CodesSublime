#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <utility>
#include <set>
#define mp make_pair
#define EPSILON 1e-6
#define PI 3.14159265
using namespace std;
#define ff first
#define ss second
int n,m;
double dist[501][501];
pair<double,int> angles[2001];
struct point{
    double x,y;
    point(double xx=0,double yy=0): x(xx), y(yy)
    {
        
    }
}points[501];
bool ok(int i,double radius)
{
    int ptr=0;
    for(int j=1;j<=n;j++)
    {
        if(i==j)continue;
        double x=points[j].x-points[i].x;
        double y=points[j].y-points[i].y;
        if(2*radius-dist[i][j]<EPSILON)
            continue;
        
        double angle_extent=(180/PI)*acos(dist[i][j]/(2*radius));
        double angle=(180/PI)*atan2(y,x);
        if(angle<0)
            angle+=360;
        angles[ptr++]=mp(angle-angle_extent,1);
        angles[ptr++]=mp(angle+angle_extent,-1);   
    }
    int ctr=0;
    sort(angles,angles+ptr);
    for(int j=0;j<ptr;j++)
    {
        if(ctr>=m)
            return true;
        ctr+=angles[j].ss;
    }
    return (ctr>=m);
}
int main()
{
    double xmax=1e-9,xmin=1e9;
    double ymax=1e-9,ymin=1e9;
    double x,y;
    scanf("%d %d",&n,&m);m--; 
    for(int i=1;i<=n;i++)
    {
        scanf("%lf %lf",&x,&y);
        xmax=max(xmax,x);
        xmin=min(x,xmin);
        ymax=max(ymax,y);
        ymin=min(ymin,y);
        points[i]=point(x,y);
    }
    
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            dist[i][j]=sqrt((points[i].x-points[j].x)*(points[i].x-points[j].x)+(points[i].y-points[j].y)*(points[i].y-points[j].y));
        
    double ans=max(abs(xmax-xmin),abs(ymax-ymin));
    for(int i=1;i<=n;i++)
    {
        double low=0,high=ans;
        double mid=(low+high)/2;
        while(high-low>1e-4)
        {
            mid=(low+high)/2;
            if(!ok(i,mid))
                low=mid;
            else
                high=mid;
        }
        ans=min(high,ans);
    }
    printf("%.6lf\n",ans);
    return 0;
}
