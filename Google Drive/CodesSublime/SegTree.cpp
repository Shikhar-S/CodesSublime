#include <iostream>
typedef long long ll;
ll tree[450000];
ll lazy[450000];
ll size,n;
using namespace std;
inline ll left(ll x){
	return 2*x;
}
inline ll right(ll x){
	return 2*x+1;
}
ll getSize(ll x){
	ll ans=1;
	while(ans<=x){
		ans=ans<<1;
	}
	return ans+1;
}
void updateUtil(ll present,ll node_start,ll node_end,ll from,ll to,ll value){
	if(lazy[present]){
		tree[present]+=(node_end-node_start+1)*lazy[present];
		if(node_start!=node_end){
			lazy[left(present)]+=lazy[present];
			lazy[right(present)]+=lazy[present];
		}
		lazy[present]=0;
	}
	if(node_start>node_end || node_start>to || node_end<from){
		return;
	}
	if(from<=node_start && to>=node_end){
		tree[present]+=(node_end-node_start+1)*value;
		if(node_start!=node_end){
			lazy[left(present)]+=value;
			lazy[right(present)]+=value;
		}
		return;
	}
	
		ll mid=node_start+(node_end-node_start)/2;
		updateUtil(left(present),node_start,mid,from,to,value);
		updateUtil(right(present),mid+1,node_end,from,to,value);
		tree[present]=tree[left(present)]+tree[right(present)];
	
}
ll queryUtil(ll present,ll node_start,ll node_end,ll from,ll to){
	if(node_start>node_end || node_start>to || node_end<from){
		return 0;
	}
	if(lazy[present]){
		tree[present]+=(node_end-node_start+1)*lazy[present];
		if(node_start!=node_end){
			lazy[left(present)]+=lazy[present];
			lazy[right(present)]+=lazy[present];
		}
		lazy[present]=0;
	}
	
	if(from<=node_start && to>=node_end)
		return tree[present];
	ll mid=node_start+(node_end-node_start)/2;
	return queryUtil(left(present),node_start,mid,from,to)+
	queryUtil(right(present),mid+1,node_end,from,to);
}
void update(ll p,ll q,ll v){
	updateUtil(1,0,n-1,p,q,v);
}
ll getSum(ll from,ll to){
	return queryUtil(1,0,n-1,from,to);
}
void printTree(){
	for(ll i=0;i<size;i++)
		cout<<tree[i]<<" ";
	cout<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	ll t;
	cin>>t;
	while(t--){
		
		cin>>n;
		ll c;
		cin>>c;
		size=getSize(n);
		for(ll i=0;i<450000;i++)
		{
				tree[i]=0;
				lazy[i]=0;
		}
		ll p,q,v;
		for(ll i=0;i<c;i++){
			ll a;cin>>a;
			if(a==0){
				cin>>p>>q>>v;
				p--;q--;
				update(p,q,v);
			}
			else{
				cin>>p>>q;
				p--;q--;		
				cout<<getSum(p,q)<<"\n";
			}
		}
			
		
		 
	}
	return 0;
}
