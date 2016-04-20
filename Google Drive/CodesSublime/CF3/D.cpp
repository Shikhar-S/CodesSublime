#include <iostream>
#define INF 100000
using namespace std;
struct Point
{
    int x;
    int y;
};
int n;
 bool onSegment(Point p, Point q, Point r)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
            q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
        return true;
    return false;
}
int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
 
    if (val == 0) return 0;  
    return (val > 0)? 1: 2; 
}
bool doIntersect(Point p1, Point q1, Point p2, Point q2)
{
    
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);
 
    // General case
    if (o1 != o2 && o3 != o4)
        return true;
 
    // Special Cases
    // p1, q1 and p2 are colinear and p2 lies on segment p1q1
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;
 
    // p1, q1 and p2 are colinear and q2 lies on segment p1q1
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;
 
    // p2, q2 and p1 are colinear and p1 lies on segment p2q2
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;
 
     // p2, q2 and q1 are colinear and q1 lies on segment p2q2
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;
 
    return false; // Doesn't fall in any of the above cases
}
bool isInside(Point polygon[], int n, Point p)
{
    // There must be at least 3 vertices in polygon[]
    if (n < 3)  return false;
 
    // Create a point for line segment from p to infinite
    Point extreme = {INF, p.y};
 
    // Count intersections of the above line with sides of polygon
    int count = 0, i = 0;
    do
    {
        int next = (i+1)%n;
 
        // Check if the line segment from 'p' to 'extreme' intersects
        // with the line segment from 'polygon[i]' to 'polygon[next]'
        if (doIntersect(polygon[i], polygon[next], p, extreme))
        {
            // If the point 'p' is colinear with line segment 'i-next',
            // then check if it lies on segment. If it lies, return true,
            // otherwise false
            if (orientation(polygon[i], p, polygon[next]) == 0)
               return onSegment(polygon[i], p, polygon[next]);
 
            count++;
        }
        i = next;
    } while (i != 0);
 
    // Return true if count is odd, false otherwise
    return count&1;  // Same as (count%2 == 1)
}
int main()
{
	int n;
	cin>>n;
	Point arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i].x>>arr[i].y;
	}
	int ans=0;
	int a,b;
	cin>>a>>b;
	cout<<"**********\n";
	for(int i=0;i<n-1;i++)
	{
		if(arr[i].x==arr[i+1].x)
		{
			Point p;
			if(arr[i].y>arr[i+1].y)
			{
				p.x=arr[i].x;
				p.y=arr[i+1].y-1;
				if(isInside(arr,n,p))
				{
					ans++;
					cout<<arr[i+1].x<<" "<<arr[i+1].y<<endl;
				}
					
			}
			else
			{
				p.x=arr[i].x;
				p.y=arr[i+1].y+1;
				if(isInside(arr,n,p))
					{
					ans++;
					cout<<arr[i+1].x<<" "<<arr[i+1].y<<endl;
				}
			}
		}
		if(arr[i].y==arr[i+1].y)
		{
			Point p;
			if(arr[i].x>arr[i+1].x)
			{
				p.y=arr[i].y;
				p.x=arr[i+1].x-1;
				if(isInside(arr,n,p))
					{
					ans++;
					cout<<arr[i+1].x<<" "<<arr[i+1].y<<endl;
				}
			}
			else
			{
				p.y=arr[i].y;
				p.x=arr[i+1].x+1;
				if(isInside(arr,n,p))
					{
					ans++;
					cout<<arr[i+1].x<<" "<<arr[i+1].y<<endl;
				}
			}
		}
	}
	cout<<ans<<endl;
}