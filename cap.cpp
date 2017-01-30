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
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#include <unordered_map>
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef vector < int > vi;
typedef vector < ll > vll;
typedef pair <int, int> pii;
typedef pair<ll, ll> pll;
#define rep(i,a,n) for(i=a;i<=n;i++)
#define per(i,n,a) for(i=n;i>=a;i--)
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define all(vi) vi.begin(), vi.end()
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define iOS ios_base::sync_with_stdio(false); cin.tie(NULL)
#define imax numeric_limits<int>::max()
#define imin numeric_limits<int>::min()
#define llmax numeric_limits<ll>::max()
#define llmin numeric_limits<ll>::min()
ll powmod(ll a,ll b) {ll res=1;if(a>=MOD)a%=MOD;for(;b;b>>=1){if(b&1)res=res*a;if(res>=MOD)res%=MOD;a=a*a;if(a>=MOD)a%=MOD;}return res;}
ll gcd(ll a , ll b){return b==0?a:gcd(b,a%b);}
/****************CODE STARTS HERE*******************/
set<pair<ll,ll> > population;
set<ll> graph[50004];
int pop[50004];
int main()
{
	ll t;
    cin>>t;
    while(t--)
    {
    	ll n;
    	cin>>n;
    	population.clear();
    	int i;
    	rep(i,1,n)
    	{
    		graph[i].clear();
    		pop[i]=0;
    	}
    	for(int i=0;i<n;i++)
    	{
    		ll x;
    		cin>>x;
    		pop[i+1]=x;
    		population.insert(mp(x,i+1));
    	}
    	for(int i=0;i<n-1;i++)
    	{
    		ll x,y;
    		cin>>x>>y;
    		graph[x].insert(y);
    		graph[y].insert(x);
    	}

    	for(int i=1;i<=n;i++)
    	{
    		graph[i].insert(i);
    		ll ans=0;
    		bool flag=true;
    		set<pair<ll,ll> >::reverse_iterator it=population.rbegin();
    		while(flag && it!=population.rend())
    		{
    			if(graph[i].find(it->ss)==graph[i].end())
    			{
    				flag=false;
    				ans=it->ss;
    			}
    			it++;
    		}
    		cout<<ans<<" ";
    	}
    	cout<<"\n";
    }
    return 0;
}