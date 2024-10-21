//https://leetcode.com/problems/redundant-connection

class Solution {
public:
    // Function to find the root (representative) of the set that u belongs to, using path compression.
    // It compresses the path by making all the nodes on the path from u to the root point directly to the root.
    int find(int par[], int u) {
        if (par[u] == u) return u; // If u is its own parent, it's the root.
        return par[u] = find(par, par[u]); // Recursively find the root and compress the path.
    }

    // Function to unite two sets with roots rt_u and rt_v. It uses union by size to ensure that the smaller set is 
    // merged into the larger one to maintain a balanced structure, which optimizes future find operations.
    void Union(int par[], int sz[], int rt_u, int rt_v) {
        if (sz[rt_u] < sz[rt_v]) swap(rt_u, rt_v); // Ensure rt_u is the larger set.
        par[rt_v] = rt_u; // Make rt_u the parent of rt_v.
        sz[rt_u] += sz[rt_v]; // Update the size of the merged set.
    }

    // Function to find the redundant edge in a graph that forms a cycle.
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ans; // Vector to store the redundant edge.
        int par[edges.size()+1]; // Array to store the parent of each node.
        int sz[edges.size()+1]; // Array to store the size of the set for each node.

        // Initialize the parent and size arrays. Each node is initially its own parent and the size of each set is 1.
        for(int i = 1; i <= edges.size(); i++) {
            par[i] = i; // Each node is its own parent.
            sz[i] = 1; // Initial size of each set is 1.
        }

        // Iterate through each edge in the graph.
        for (auto ch : edges) {
            int u = ch[0]; // First node of the edge.
            int v = ch[1]; // Second node of the edge.

            // Find the roots of the sets that u and v belong to.
            int rt_u = find(par, u);
            int rt_v = find(par, v);

            // If u and v have the same root, adding this edge would form a cycle.
            if (rt_u == rt_v) {
                ans.push_back(u); // Store the redundant edge.
                ans.push_back(v);
                break; // No need to check further once the redundant edge is found.
            }

            // Otherwise, unite the two sets.
            Union(par, sz, rt_u, rt_v);
        }

        return ans; // Return the redundant edge.
    }
};
