//https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/minimum-nodes-e023e51e/


#include <bits/stdc++.h>
using namespace std;

vector<int>v;
vector<int>adj[100005];
int ans=INT_MAX;
void dfs(int node, int par,int target,int cnt, long long sum){
	sum+=v[node];
	cnt++;
	if(sum>=target){ans=min(cnt,ans);return;}
	for(int ch:adj[node]){
		if(ch==par)continue;
		dfs(ch,node,target,cnt,sum);
	}
}

int main(){
	int N,Q;
	cin>>N>>Q;
	v.push_back(0);
	for(int i=0;i<N;i++){
		int val;
		cin>>val;
		v.push_back(val);
	}

	for(int i=0;i<N-1;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i=0;i<Q;i++){
		int x,k;
		cin>>x>>k;
		dfs(x,x,k,0,0);
		if(ans==INT_MAX)cout<<-1<<endl;
		else{
			cout<<ans<<endl;
			ans=INT_MAX;
		}
		
	}

	
	

}
