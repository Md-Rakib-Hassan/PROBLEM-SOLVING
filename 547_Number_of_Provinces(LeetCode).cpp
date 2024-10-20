//https://leetcode.com/problems/number-of-provinces

class Solution {
public:

    // Helper function to find the root (or representative) of a node 'u'
    // using path compression. This helps in keeping the tree flat.
    int find(int parents[], int u) {
        // If 'u' is its own parent, it is the root, so return 'u'
        if (parents[u] == u) return u;
        // Recursively find the root of 'u' and apply path compression
        // by updating the parent of 'u' to the root directly
        return parents[u] = find(parents, parents[u]);
    }

    // Helper function to unite two disjoint sets represented by 'u' and 'v'
    // using union by size (attach the smaller tree under the larger one)
    void Union(int parents[], int sizes[], int u, int v) {
        // Find the roots of both 'u' and 'v'
        int root_u = find(parents, u);
        int root_v = find(parents, v);
        // If both 'u' and 'v' have the same root, they are already in the same set
        if (root_u == root_v) return;
        // Union by size: attach the smaller set to the larger one
        if (sizes[root_u] < sizes[root_v]) swap(root_u, root_v);
        // Make 'root_u' the parent of 'root_v'
        parents[root_v] = root_u;
        // Update the size of the new root's set
        sizes[root_u] += sizes[root_v];
    }

    // Main function to find the number of connected components (provinces)
    // in the graph represented by 'isConnected'
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(); // Number of nodes (cities/provinces)
        int parents[n + 1];         // Array to store the parent of each node
        int sizes[n + 1];           // Array to store the size of each set

        // Initialize each node to be its own parent (self-loop)
        // and set the size of each set to 1
        for (int i = 1; i <= n; i++) {
            parents[i] = i;
            sizes[i] = 1;
        }

        // Traverse the matrix and unite nodes if they are connected
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // If 'i' and 'j' are directly connected, unite their sets
                if (isConnected[i][j]) Union(parents, sizes, i + 1, j + 1);
            }
        }

        int ans = 0; // Variable to count the number of distinct sets (provinces)
        // Count the number of roots, as each root represents a connected component
        for (int i = 1; i <= n; i++) {
            if (parents[i] == i) ans++;
        }

        return ans; // Return the number of connected components (provinces)
    }
};
