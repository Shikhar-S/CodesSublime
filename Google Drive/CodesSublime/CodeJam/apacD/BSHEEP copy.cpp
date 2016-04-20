#include <iostream>
#include <algorithm>
#include <stack>
#include <cmath>
using namespace std;
struct data{
	int x,y;
	int idx;
};
data arr[100005];
int dist(data a,data b)
{
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
int orientation(data p,data q,data r)
{
	return (q.y-p.y)*(r.x-q.x)-(q.x-p.x)*(r.y-q.y);
}
bool compare(data &a,data &b)
{
	int x=orientation(arr[0],a,b);
	if(x==0)
		return dist(arr[0],a)<dist(arr[0],b);
	return x>0;

}
void swap(int x,int y)
{
	data temp=arr[x];
	arr[x]=arr[y];
	arr[y]=temp;
}
data nextTotop(stack<int> &hull)
{
	int pu=hull.top();hull.pop();
	data ans=arr[hull.top()];
	hull.push(pu);
	return ans;
}
int main(){
	int t;cin>>t;
	while(t--)
	{
		int n;cin>>n;
		
		for(int i=0;i<n;i++)
		{
			cin>>arr[i].x;
			cin>>arr[i].y;
			arr[i].idx=i+1;
		}
		int anchor=0;
		for(int i=0;i<n;i++)
		{
			if(arr[i].y<arr[anchor].y)
			{
				anchor=i;
			}
			else if(arr[i].y==arr[anchor].y && arr[i].x<arr[anchor].x)
			{
				anchor=i;
			}
		}
		swap(anchor,0);
		sort(arr+1,arr+n,compare);
		int sz=1;
		for(int i=1;i<n;i++)
		{
			while(i<n-1 && orientation(arr[0],arr[i],arr[i+1])==0)
				i++;
			arr[sz++]=arr[i];
		}
		if(sz<3)continue;
		stack<int> hull;
		hull.push(0);
		hull.push(1);
		hull.push(2);
		for(int i=3;i<sz;i++)
		{
			while(orientation(nextTotop(hull),arr[hull.top()],arr[i])>=0)
			{
				hull.pop();
			}
			hull.push(i);
		}
		stack<int> answer;
		double ans=0;
		data prev=arr[hull.top()];
		answer.push(prev.idx);
		data temp=prev;
		hull.pop();
		data current;
		while(!hull.empty())
		{
			current=arr[hull.top()];
			ans+=sqrt(dist(current,prev));
			answer.push(current.idx);

			hull.pop();
			prev=current;
		}
		ans+=sqrt(dist(current,temp));
		printf("%.2lf\n",ans);
		while(!answer.empty())
		{
			cout<<answer.top()<<" ";
			answer.pop();
		}
		cout<<endl;
	}
}