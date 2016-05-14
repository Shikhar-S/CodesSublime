#include <iostream>
#include <utility>
#include <algorithm>
#include <cstdio>
using namespace std;
int arr[300000];
bool number[1000001];
int LM[300000];
int PI[1000001];
int n;
struct query{
    int l,r;
    int ans;
    int idx;
};

bool compare(const query &a,const query &b){
    if(a.l==b.l)
        return a.r<b.r;
    else
        return a.l<b.l;
}
bool comparefi(const query &a,const query &b){
    return a.idx<b.idx;
}
void update(int x,int val){
    for(;x<=n;x +=(x & -x))
        arr[x]+=val;
}
int get(int x){
    int ans=0;
    
    for(;x>0;x-=(x & -x))
        ans+=arr[x];
    return ans;
}
query qu[200001];
int main(){
    for(int i=0;i<300000;i++)
    {
        arr[i]=0;
    }
    for(int i=0;i<1000001;i++)
    {
        PI[i]=-1;
        number[i]=false;
    }
    scanf("%d",&n);
    int v[n+1];
    for(int i=1;i<=n;i++)
        scanf("%d",&v[i]);
    for(int i=n;i>0;i--){
        LM[i]=PI[v[i]];
        PI[v[i]]=i;
        //cout<<LM[i]<<" ";
    }
    
    int q;
   	scanf("%d",&q);
    for(int i=0;i<q;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        qu[i].l=x;
        qu[i].r=y;
        qu[i].ans=0;
        qu[i].idx=i;
    }
    sort(qu,qu+q,compare);
    for(int i=1;i<=n;i++){
        if(!number[v[i]]){
            number[v[i]]=true;
            update(i,1);
        }
    }
    int prev=1;
    for(int i=0;i<q;i++){
        int to=qu[i].l;
        for(;prev<to;prev++){		//unmarking
            if(number[v[prev]]){
                update(prev,-1);
                number[v[prev]]=false;
                if(LM[prev]!=-1){
                    //cout<<LM[v[prev]]<<" ";
                    update(LM[prev],1);
                    number[v[prev]]=true;
                }
            }
        }
        qu[i].ans=get(qu[i].r)-get(qu[i].l-1);
    }
    sort(qu,qu+q,comparefi);
    for(int i=0;i<q;i++)
        printf("%d\n",qu[i].ans);
}