// https://leetcode.com/problems/number-of-operations-to-make-network-connected

class Solution {
public:

    // Function to find the root of a node `u` in the disjoint-set (Union-Find) with path compression.
    int find(int par[], int u) {
        if (par[u] == u) return u; // If `u` is its own parent, return `u` (base case).
        return par[u] = find(par, par[u]); // Recursively find the root and apply path compression.
    }

    // Union function to merge two sets (represented by `root_u` and `root_v`) based on size.
    void Union(int par[], int sz[], int root_u, int root_v) {
        // Always attach the smaller tree under the larger tree for optimization.
        if (sz[root_u] < sz[root_v]) swap(root_u, root_v);
        par[root_v] = root_u; // Make `root_u` the parent of `root_v`.
        sz[root_u] += sz[root_v]; // Update the size of the new root `root_u`.
    }

    // Main function to determine the minimum number of extra operations required to connect all computers.
    int makeConnected(int n, vector<vector<int>>& connections) {
        int par[n]; // Parent array for the Union-Find.
        int sz[n];  // Size array to track the size of each set.

        // Initialize each node as its own parent and set size to 1.
        for (int i = 0; i < n; i++) {
            par[i] = i;
            sz[i] = 1;
        }

        int remaining_connection = 0; // Counter for redundant connections.
        
        // Process each connection to union the respective nodes.
        for (auto ch : connections) {
            int root_u = find(par, ch[0]); // Find root of node `ch[0]`.
            int root_v = find(par, ch[1]); // Find root of node `ch[1]`.
            
            // If both nodes have the same root, the connection is redundant.
            if (root_u == root_v) {
                remaining_connection++; // Increment redundant connection counter.
                continue; // Skip this connection.
            }
            // Otherwise, union the two nodes.
            Union(par, sz, root_u, root_v);
        }

        // Find the largest connected component.
        int mx_sz = 0, mx_node;
        for (int i = 0; i < n; i++) {
            if (mx_sz < sz[i]) {
                mx_sz = sz[i]; // Update max size.
                mx_node = i; // Track the node with the largest size.
            }
        }

        int mx_root = find(par, mx_node); // Get the root of the largest component.
        int total_wire_remaining = remaining_connection; // Store the total number of redundant connections.

        // Try to connect all disconnected components.
        for (int i = 0; i < n; i++) {
            int new_root = find(par, i); // Find the root of node `i`.
            if (new_root != mx_root) { // If it's not in the largest component.
                Union(par, sz, mx_root, new_root); // Union it with the largest component.
                remaining_connection--; // Decrement redundant connections since a wire is used.
            }
        }

        // If there are not enough redundant connections to connect all components, return -1.
        if (remaining_connection < 0) return -1;
        return total_wire_remaining - remaining_connection; // Return the number of operations required.
    }
};
