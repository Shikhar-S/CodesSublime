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
bool visited[100005];
multiset<int> graph[100006];
stack<int> cover;
stack<int> ans;
multiset<int> fnlAns[100005];
vector<pair<int,int> > inp;
int n,e;
int X;
void finishAll(int x)
{
    if(x==X)
    {
        return;
    }
    cover.push(x);
    visited[x]=true;
    for(multiset<int>::iterator it=graph[x].begin();it!=graph[x].end();)
    {
        int to=*it;
        graph[to].erase(graph[to].find(x));
        graph[x].erase(graph[x].find(*it));
        finishAll(to);
        return;
    }
    
}
int main()
{
    cin>>n>>e;

    int i;
    rep(i,1,n)
    visited[i]=false;
    int a,b;
    for(int i=1;i<=e;i++)
    {
        cin>>a>>b;
        graph[a].insert(b);
        graph[b].insert(a);
        inp.pb(mp(a,b));
    }

    bool flag=true;
    for(int i=1;i<=n;i++)
    {
        if(graph[i].size()%2!=0)
        {
            cout<<"NO\n";
            return 0;
        }
    }
    cover.push(1);
    while(!cover.empty())
    {
        int t=cover.top();
        X=t;
        cover.pop();
        if(graph[t].size()>0)
        {
            cover.push(t);
            visited[t]=true;
            int to=*(graph[t].begin());
            graph[to].erase(graph[to].find(t));
            graph[t].erase(graph[t].find(to));
            finishAll(to);
        }
        ans.push(t);
    }
    rep(i,1,n)
    {
        flag= flag & visited[i];
    }
    if(flag)
    {
        cout<<"YES\n";
        int a=ans.top();
        ans.pop();
        while(!ans.empty())
        {
            int b=ans.top();
            ans.pop();
            fnlAns[a].insert(b);
            a=b;
        }
        rep(i,0,e-1)
        {
        	int from=inp[i].ff;
        	int to=inp[i].ss;
        	if(fnlAns[from].find(to)!=fnlAns[from].end())
        		cout<<from<<" "<<to<<"\n";
        	else
        		cout<<to<<" "<<from<<"\n";
        }
    }
    else
    {
    	cout<<"NO\n";
    }
    return 0;
}