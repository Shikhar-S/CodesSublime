#include <iostream>
#include <vector>
#include <utility>
#define mod 1000000007
typedef long long ll;
ll factorial[100001];
int neighbours[100001];
using namespace std;
int main(){
    
    factorial[0]=1;
    factorial[1]=1;
    neighbours[0]=0;neighbours[1]=0;
    for(int i=2;i<=100000;i++){
        neighbours[i]=0;
        factorial[i]=(i*factorial[i-1])%mod;
    }
    ll powers[9];
    powers[0]=1;
    for(int i=1;i<=8;i++){
        powers[i]=2*powers[i-1];
    }
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<pair<int,int> > vp;
        ll ans=0;
        for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            vp.push_back(make_pair(x,y));
        }
        for(int select=0;select<powers[m];select++){
            int copy=select;
            vector<pair<int,int> > selected;
            int c=0;
            while(copy>0){
                int rem=copy%2;
                if(rem==1){
                    selected.push_back(vp[c]);
                }
                copy=copy/2;
                c++;
            }
            int groups=0;
            int elements=0;
            int sz=selected.size();
            vector<int> reset;
            vector<vector<pair<int,int> > > vgroup;
            for(int i=0;i<sz;i++){
                int a=selected[i].first;
                int b=selected[i].second;
                if(neighbours[a]==2 || neighbours[b]==2){
                    groups=-1;
                    elements=-1;
                    break;
                }
                else if(neighbours[a]==1 && neighbours[b]==1){
                    groups--;
                    neighbours[a]++;
                    neighbours[b]++;
                    int index[2];
                    index[0]=-1;index[1]=-1;
                    int brakes=0;
                    for(int r=0;r<vgroup.size();r++)
                    {
                        for(int l=0;l<vgroup[r].size();l++)
                        {
                            if(vgroup[r][l].first == a || vgroup[r][l].second==a || vgroup[r][l].first == b || vgroup[r][l].second==b)
                            {
                                index[brakes]=r;
                                brakes++;
                            }
                        }
                        if(brakes>1){
                            
                            groups=-1;
                            elements=-1;
                            break;
                        }
                    }
                    if(groups!=-1){
                        for(int r=0;r<vgroup[index[1]].size();r++){
                            vgroup[index[0]].push_back(vgroup[index[1]][r]);
                        }
                        vgroup[index[0]].push_back(selected[i]);
                        vgroup[index[1]].clear();
  
                    }
                    
                }
                else if(neighbours[a]==1 || neighbours[b]==1){
                    neighbours[a]++;neighbours[b]++;
                    elements++;
                    reset.push_back(a);
                    reset.push_back(b);
                    for(int r=0;r<vgroup.size();r++){
                        for(int l=0;l<vgroup[r].size();l++){
                            if(vgroup[r][l].first == a || vgroup[r][l].second==a || vgroup[r][l].first == b || vgroup[r][l].second==b){
                                
                                vgroup[r].push_back(selected[i]);
                                break;
                            }
                        }
                    }
                }
                else
                {
                    neighbours[a]++;
                    neighbours[b]++;
                    elements+=2;
                    groups+=1;
                    reset.push_back(a);
                    reset.push_back(b);
                    vector<pair<int,int> > temporary;
                    temporary.push_back(selected[i]);
                    vgroup.push_back(temporary);
                }
            }
            ll temp;
            if(groups!=-1){
                temp=factorial[n-elements+groups];
                temp=(temp*powers[groups])%mod;
            }
            else
            {
                temp=0;
            }
            
            ans=(sz%2==0)?((ans+temp)%mod):(ans-temp);
            for(int i=0;i<reset.size();i++){
                neighbours[reset[i]]=0;
            }
        }
        
        cout<<ans<<endl;
        
    }
    return 0;
}