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
char g[2000][2000];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n,m;
    	cin>>n>>m;
    	int i,j;
    	rep(i,0,1001)
    	rep(j,0,1001)
    	g[i][j]='_';

    	rep(i,1,n)
    	rep(j,1,m)
    	cin>>g[i][j];
    	
    	/*rep(i,1,n){
    	rep(j,1,m)
    	cout<<g[i][j];
    	cout<<endl;}*/
    	
    	bool flag=true;
    	
    	rep(i,1,n)
    	{
    		rep(j,1,m)
    		{
    			if(g[i][j]=='B')
    			{
    				if(g[i+1][j]!='B' && i!=n)
    					flag=false;
    			}
    			else if(g[i][j]=='W')
    			{
    				if((g[i][j-1]!='W' && g[i][j-1]!='B') || (g[i][j+1]!='W' && g[i][j+1]!='B') || (g[i+1][j]!='B' && g[i+1][j]!='W'))
    				{
    					flag=false;
    				}
    			}
    			else if(g[i][j]=='A')
    			{
    				if(g[i-1][j]!='A' && i!=1)
    					flag=false;
    			}
    		}
    	}
    	if(flag)
    	{
    		cout<<"yes\n";
    	}
    	else
    	{
    		cout<<"no\n";
    	}

    }
    return 0;
}