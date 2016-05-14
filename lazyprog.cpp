#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
#include <utility>
using namespace std;
typedef long long unsigned llu;
typedef long long lld;
typedef long ld;
#define fl(i,a) for(i=0;i<a;i++)
#define fe(i,a) for(i=0;i<=a;i++)
#define slld(n) scanf("%lld",&n)
struct task{
    lld bonus,usual,due;
    friend bool operator<(const task a,const task b)
    {
        return a.bonus<b.bonus;
    }
};
bool comp(task a,task b)
{
    return a.due<b.due;
}
int main()
{
    
    lld t;
    slld(t);
    while(t--)
    {
        lld n;slld(n);
        task tasks[n];
        lld i;
        fl(i,n)
        {
            slld(tasks[i].bonus);
            slld(tasks[i].usual);
            slld(tasks[i].due);
        }
        sort(tasks,tasks+n,comp);
        lld cur=0;
        double x=0;
        priority_queue<task> pq;
        fl(i,n)
        {
            cur+=tasks[i].usual;
            if(cur<=tasks[i].due)
            {
                pq.push(tasks[i]);
            }
            else
            {
                pq.push(tasks[i]);
                while(cur>tasks[i].due)
                {
                    task temp=pq.top();
                    pq.pop();
                    
                    lld lim=min(temp.usual,cur-tasks[i].due);
                    x+=((double)lim/temp.bonus);
                    if(lim<temp.usual)
                    {
                        temp.usual-=lim;
                        pq.push(temp);
                    }
                    cur-=lim;
                }
                
            }
        }
        printf("%.2lf\n",x);
    }
    return 0;
}