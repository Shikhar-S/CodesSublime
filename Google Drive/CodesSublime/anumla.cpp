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
#define pfd(n) printf("%d",n)
#define pfld(n) printf("%ld",n)
#define pflld(n) printf("%lld ",n)

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

int main()
{
    lld t;
    slld(t);
    while(t--)
    {
        lld n;slld(n);
        lld num=1<<n;
        
        lld i;
        multiset<lld> s;
        fl(i,num)
        {
            lld x;slld(x);
            s.insert(x);
        }
        vector<lld> ans;
        s.erase(s.begin());
        vector<lld> todelete;
        
        lld temp=0;
        while(!s.empty() && ans.size()<n)
        {
            lld j;
            /*fu(j,1,pow(2,ans.size()))
             {
             lld sum=0;
             bitset<15> bs(j);
             for( size_t k=0;k<bs.size();k++)
             {
             if(bs.test(k))
             sum+=ans[k];
             }
             multiset<lld>::iterator it=s.find(sum);
             if(it!=s.end())
             {
             s.erase(it);
             }
             
             }*/
            lld x=*s.begin();
            ans.pb(x);
            
            temp=todelete.size();
            fl(j,temp)
            {
                lld sum=todelete[j]+x;
                todelete.pb(sum);
                multiset<lld>::iterator it=s.find(sum);
                if(it!=s.end())
                {
                    s.erase(it);
                }
            }
            todelete.pb(x);
            s.erase(s.begin());
            
        }
        vector<lld>::iterator it;
        tr(ans,it)
        pflld(*it);
        printf("\n");
    }
    
    return 0;
}
