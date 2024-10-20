//https://leetcode.com/problems/graph-connectivity-with-threshold

class Solution {
public:

    // Function to find the root parent of node 'u' in the Union-Find data structure.
    // This function implements path compression to make future queries faster by 
    // directly connecting nodes to their root parent.
    int find(int parents[], int u) {
        if (parents[u] == u) return u; // If 'u' is its own parent, return 'u'.
        return parents[u] = find(parents, parents[u]); // Recursively find the root parent and compress the path.
    }

    // Function to perform union of two sets containing nodes 'u' and 'v'.
    // It connects the smaller tree under the root of the larger tree to keep the tree balanced.
    void Union(int parents[], int sizes[], int u, int v) {
        int root_u = find(parents, u); // Find the root of 'u'.
        int root_v = find(parents, v); // Find the root of 'v'.
        
        if (root_u == root_v) return; // If both have the same root, they are already connected.
        
        // Union by size: attach the smaller tree (root_v) under the larger tree (root_u).
        if (sizes[root_u] < sizes[root_v]) swap(root_u, root_v); 
        
        parents[root_v] = root_u; // Make root_u the parent of root_v.
        sizes[root_u] += sizes[root_v]; // Update the size of the new root.
    }

    // Main function to determine which pairs of nodes are connected based on the threshold.
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        int parents[n+1]; // Array to store the parent of each node (for Union-Find).
        int sizes[n+1]; // Array to store the size of each tree (for Union-Find by size).
        
        // Initialize each node to be its own parent and set size to 1.
        for (int i = 0; i < n+1; i++) {
            parents[i] = i;
            sizes[i] = 1;
        }
        
        // Loop through each number greater than the threshold and union its multiples.
        for (int i = threshold + 1; i <= n; i++) {
            for (int j = i; j <= n; j += i) {
                Union(parents, sizes, i, j); // Union node 'i' with its multiples.
            }
        }

        vector<bool> ans; // To store the result of each query.

        // For each query, check if both nodes belong to the same connected component.
        for (auto q : queries) {
            if (find(parents, q[0]) == find(parents, q[1])) 
                ans.push_back(true); // If the roots are the same, they are connected.
            else 
                ans.push_back(false); // Otherwise, they are not connected.
        }

        return ans; // Return the results for all queries.
    }
};
