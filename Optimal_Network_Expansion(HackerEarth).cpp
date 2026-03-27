//https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/optimal-network-expansion-de452a46/

#include <bits/stdc++.h>
using namespace std;
vector<int>adj[100005];
bool vis[100005];


int dfs(int node){
	if(vis[node])return 0;
	int cnt=1;
	vis[node]=true;
	for(int ch:adj[node]){
		cnt+=dfs(ch);
	}
	return cnt;
}

int main() {
	int n,m,k;
	cin>>n>>m>>k;

	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int>network;
	for(int i=1;i<=n;i++){
		if(!vis[i])network.push_back(dfs(i));
	}

	sort(network.begin(),network.end(),greater<int>());
	int ans=0;

	for(int i=0;i<k+1;i++){
		ans+=network[i];
	}
	cout<<ans<<endl;



	return 0;
}