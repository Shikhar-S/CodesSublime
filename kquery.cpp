#include <cstdio>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
int n;
int arr[30001];
struct data{
    int l,r,k;
    int idx;
    int ans;
};
struct array
{
	int ele,index;
};
void fastscan(int *a)
    {
        register char c=0;
    while (c<33) c=getchar_unlocked();
    *a=0;
    while (c>33)
    {
        *a=*a*10+c-'0';
        c=getchar_unlocked();
    }
    }
bool compare(data &a,data &b){
    return a.k>=b.k;
}
bool comparefi(data &a,data &b){
    return a.idx<=b.idx;
}
bool compinp(array &a,array &b){
	return a.ele>b.ele;
}
void update(int x,int val){
    for(;x<=n;x+=(x&-x)){
        arr[x]+=val;
    }
}
int get(int x){
    int ans=0;
    for(;x>0;x-=(x&-x)){
        ans+=arr[x];
    }
    return ans;
}
int main(){
    fastscan(&n);
    array v[n];
    for(int i=0;i<30001;i++){
        arr[i]=0;
    }
    for(int i=0;i<n;i++)
        {
        	fastscan(&v[i].ele);
        	v[i].index=i;
        }
    int q;
    fastscan(&q);
    
    data queries[q];
    
    for(int i=0;i<q;i++){
        int a,b,c;
        fastscan(&a);
        fastscan(&b);
        fastscan(&c);
        queries[i].l=a;
        queries[i].r=b;
        queries[i].idx=i;
        queries[i].ans=0;
        queries[i].k=c;
    }
    sort(queries,queries+q,compare);
    sort(v,v+n,compinp);
    int prev=INT_MAX;
    int j=0;
    for(int i=0;i<q;i++){
        if(prev!=queries[i].k){
            
            for(;j<n;j++){
                if(v[j].ele>queries[i].k && v[j].ele<=prev){
                    update(v[j].index+1,1);
                }
                else
                	break;
            }
            prev=queries[i].k;
        }
        queries[i].ans=get(queries[i].r)-get(queries[i].l-1);
    }
    sort(queries,queries+q,comparefi);
    for(int i=0;i<q;i++){
        printf("%d\n",queries[i].ans);
    }
}