#include <vector>
#include <iostream>
#include <string>
using namespace std;
vector<string> v;
vector<string> possible;

void form(int n,string s)
{
    if(s.length()==n+1)
    {
        return;
    }
    if(s.length()>0)
        v.push_back(s);
    form(n,s+'A');
    form(n,s+'B');
}
void check(int i,string x,string y)
{
    if(i==y.length()+1)
    {
        
        return;
    }
    if (x.length()>0 && i==y.length())
    {
        possible.push_back(x);
    }
    
    check(i+1,x,y);
    if(i<y.length())
    check(i+1,x+y[i],y);
}
int main()
{
    int t;
    cin>>t;
    string temp;
    while(t--)
    {
        v.clear();possible.clear();
        cin>>temp;
        int n=temp.length();
        form(n,"");
        //for(int i=1;i<=n;i++)
            check(0,"",temp);
        int b=possible.size();
        int a=v.size();
        int i;
        for(i=0;i<a;i++)
        {
            int cnt=0;
            for(int j=0;j<b && cnt<=2;j++)
            {
                if(possible[j]==v[i])
                    cnt++;
            }
            if (cnt==2)
            {
                cout<<v[i]<<endl;
                break;
            }
        }
        if (i==a)
        {
            cout<<-1<<endl;
        }
    }
}