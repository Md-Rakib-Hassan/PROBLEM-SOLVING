//https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        bool vis[V]={false};
        int src=0;
        vector<int>path;
        queue<int>q;
        q.push(src);
        
        while(!q.empty()){
            int par=q.front();
            q.pop();
            if(!vis[par]){
            vis[par]=true;
            path.push_back(par);
            for(auto ch:adj[par]){
                q.push(ch);
            }
            }
            
        }
        
        return path;
        
    }
};



//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}