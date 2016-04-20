#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
using namespace std;
typedef long long unsigned llu;
typedef long long lld;
typedef long ld;
//definition
#define vi vector < int >
#define vld vector < ld >
#define vlld vector < lld >
#define pii pair <int, int>
#define plld pair<lld, lld>
#define vpii vector< pii >
#define vplld vector< plld >
#define gc getchar_unlocked
#define pc putchar_unlocked
//important constants
#define MOD 1000000007
#define MAX 1000000
//looping
#define fl(i,a) for(i=0;i<a;i++)
#define fe(i,a) for(i=0;i<=a;i++)
#define fu(i,a,n) for(i=a;i<n;i++)
#define fue(i,a,n) for(i=a;i<=n;i++)
#define fd(i,n,a) for(i=n;i>a;i--)
#define fde(i,n,a) for(i=n;i>=a;i--)
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
//input output
#define sd(n) scanf("%d",&n)
#define sld(n) scanf("%ld",&n)
#define slld(n) scanf("%lld",&n)
#define pfd(n) printf("%d\n",n)
#define pfld(n) printf("%ld",n)
#define pflld(n) printf("%lld\n",n)

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define all(vi) vi.begin(), vi.end()
#define mem(i,n) memset(i,n,sizeof(i))
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL)
#define imax numeric_limits<int>::max()
#define imin numeric_limits<int>::min()
#define ldmax numeric_limits<ld>::max()
#define ldmin numeric_limits<ld>::min()
#define lldmax numeric_limits<lld>::max()
#define lldmin numeric_limits<lld>::min()
//end of definition
bool comp(pii &a,pii &b)
{
    return a.ff<b.ff;
}
int main()
{
    lld t;
    slld(t);
    while(t--)
    {
        lld n,i=0;
        slld(n);
        pii stations[10001];
        fl(i,n)
        {
            lld x,y;
            slld(x);
            slld(y);
            stations[i]=mp(x,y);
        }
        stations[n]=mp(0,0);
        priority_queue<lld> pq;
        sort(stations,stations+n+1,comp);
        lld p,q;
        slld(p);slld(q);
        lld c=0;i=n-1;
        
        fde(i,n,0){
            if(p<=q)
            {
                pflld(c);
                break;
            }
            else if(p>q && p-q>stations[i].ff)
            {
                if(!pq.empty())
                {
                    lld x=pq.top();
                    pq.pop();
                    q+=x;
                    c++;
                    i++;
                }
                else
                {
                    printf("-1\n");
                    break;
                }
                
            }
            else if(p-q<=stations[i].ff)
            {
                pq.push(stations[i].ss);
            }
        }
        
        
    }
    return 0;
}
