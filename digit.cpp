#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <set>
typedef long long ll;
using namespace std;
string s;
ll N,M,X,Y,t;
set<ll> dp[301][301];
ll gcd(ll a , ll b)
{
    return b==0?a:gcd(b,a%b);
}
void f(ll n,ll hcf,ll y)
{
    if(n<0)
        return;
    
    if(n==0)
    {
        if(y>=X)
            dp[0][y].insert(hcf);
        return;
    }
    if(y>Y)
        return;
    
    if(dp[n][y].find(hcf)!=dp[n][y].end())
        return;
    
    
    ll num=0;
    ll pw=1;
    for(int j=1;j<=min(n,M);j++)
    {
        num=(s[n-j+1]-'0')*pw+num;
        ll hh=gcd(hcf,num);
        f(n-j,hh,y+1);
        dp[n-j][y+1].insert(hh);
        pw*=10;
    }
}

int main()
{
    cin>>t;
    while(t--)
    {
        cin>>N;
        cin>>s;
        cin>>M>>X>>Y;
        s='$'+s;
        


        for(ll i=0;i<=300;i++)
            for(ll j=0;j<=300;j++)
                dp[i][j].clear();


        ll ans=0;
        ll num=0,pw=1;
        for(int i=1;i<=min(N,M);i++)
        {
            num=((s[N-i+1]-'0')*pw)+num;
            f(N-i,num,0);
            pw*=10;
        }
        for(int j=X;j<=Y;j++)
        {
            if(!(dp[0][j].empty()))
                ans=max(ans,*(dp[0][j].rbegin()));     
        }
        printf("%lld\n", ans);
    }   
    return 0;
}