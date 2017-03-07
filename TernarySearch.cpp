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
double d[60001];
double v[60001];
int n;
double f(double x)
{
    double ans=1e-10;
    for(int i=0;i<n;i++)
    {
        ans=max(ans,abs(d[i]-x)/v[i]);
    }
    return ans;
}
int main()
{
    cin>>n;
    int i;
    double left=1e10;
    double right=1e-10;
    rep(i,0,n-1)
    {
        cin>>d[i];
        left=min(left,d[i]);
        right=max(right,d[i]);
    }
    rep(i,0,n-1)
    cin>>v[i];
    while(right-left>1e-6)
    {
        double m1=left+(right-left)/3;
        double m2=right-(right-left)/3;
        //cout<<f(m1)<<" ------"<<f(m2)<<endl;
        if(f(m1)>=f(m2))
        {
            left=m1;
        }
        else if(f(m1)<f(m2))
        {
            right=m2;
        }
       // cout<<left<<" "<<right<<endl;
    }
    printf("%.12lf\n",f(left));
    //cout<<f(left)<<endl;
    return 0;
}