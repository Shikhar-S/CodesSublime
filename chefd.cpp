#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int two[100001];
int three[100001];
int five[100001];
int arr[100001];
int n,p;
inline void update(int x,int val,int arr[]){
    for(;x<=n;x+=(x&-x)){
        arr[x]+=val;
    }
}
inline int get(int x,int arr[]){
    int ans=0;
    for(;x>0;x-=(x&-x)){
        ans+=arr[x];
    }
    return ans;
}
int fnd(int x,int l,int r,int sums[]){
    int mid=-1;
    int idx=-1;
    while(l<=r){
        mid=(l+r)/2;
        int temp=get(mid,sums);
        if(temp==x){
        	if(arr[mid]%p==0){
        		idx=mid;
            	break;
        	}
        	else r=mid-1;
    	}
        else if(temp>x){
            r=mid-1;
        }
        else
            l=mid+1;
    }
    return idx;
}
inline void upd(int x,int i,int val){
    if(x%2==0)
        update(i,val,two);
    if(x%3==0)
        update(i,val,three);
    if(x%5==0)
        update(i,val,five);
}
int main(){
    scanf("%d",&n);
    
    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
        upd(arr[i],i,1);
    }
    int q;
    scanf("%d",&q);
    for(int i=0;i<q;i++){
        int sw;
        scanf("%d",&sw);
        switch(sw){
            case 1:{
                int l,r,sum;
                int idx=-1;
                scanf("%d %d %d",&l,&r,&p);
                switch (p){
                    case 2:sum=get(l-1,two);
                        idx=fnd(sum+1,l,r,two);
                        break;
                    case 3:sum=get(l-1,three);
                        idx=fnd(sum+1,l,r,three);
                        break;
                    case 5:sum=get(l-1,five);
                        idx=fnd(sum+1,l,r,five);
                        break;
                }
                vector<int> v;
                while(idx!=-1){
                    v.push_back(idx);
                    
                    switch (p){
                        case 2:sum=get(idx,two);
                            idx=fnd(sum+1,idx,r,two);
                            break;
                        case 3:sum=get(idx,three);
                            idx=fnd(sum+1,idx,r,three);
                            break;
                        case 5:sum=get(idx,five);
                            idx=fnd(sum+1,idx,r,five);
                            break;
                    }
                    
                }
                int len=v.size();
                for(int j=0;j<len;j++){
                    int temp=arr[v[j]]/p;
                    if(temp%p!=0){
                        upd(arr[v[j]],v[j],-1);
                        arr[v[j]]=temp;
                        upd(temp,v[j],1);
                    }
                    else
                    {
                    	arr[v[j]]=temp;
                    }
                    
                }
                break;
            }
            case 2:
            {
                int l,d;
                scanf("%d %d",&l,&d);
                
                upd(arr[l],l,-1);
                arr[l]=d;
                upd(d,l,1);
                break;
            }
        }
    }
    for(int i=1;i<=n;i++){
        printf("%d ",arr[i]);
    }
    
}