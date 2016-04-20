#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> v[6];
int calc(char x,int iter,int n)
{
    if(iter==n-1)
    {
        return 1;
    }
    if(iter!=n-1 && v[x-'a'].size()==0)
    {
        return 0;
    }
    else
    {
        int y=0;
        
        for(int i=0;i<v[x-'a'].size();i++)
        {
            y+=calc(v[x-'a'][i][0],iter+1,n);
            
        }
        
        return y;
    }
}
int main()
{
    int q,n;
    cin>>n>>q;
    char c;
    string s;
    for(int i=0;i<q;i++)
    {
        cin>>s;
        cin>>c;
        v[c-'a'].push_back(s);
    }
    
    cout<<calc('a',0,n)<<endl;
    
}