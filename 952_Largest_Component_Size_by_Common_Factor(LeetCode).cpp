//https://leetcode.com/problems/largest-component-size-by-common-factor

class Solution {
public:
    // Find the representative (root) of the set that element 'u' belongs to.
    // Uses path compression to flatten the structure, optimizing future queries.
    int find(int par[], int u) {
        if (par[u] == u)return u;  // 'u' is the representative of its own set.
        // Recursively find the root and compress the path by pointing 'u' directly to the root.
        return par[u] = find(par, par[u]);
    }

    // Union operation to combine the sets of elements 'u' and 'v'.
    // Uses union by size to ensure the smaller set is merged into the larger one, optimizing tree height.
    void Union(int par[], int sz[], int u, int v) {
        int rt_u = find(par, u);  // Find the root of 'u'
        int rt_v = find(par, v);  // Find the root of 'v'
        
        if (rt_u == rt_v)return;  // If both have the same root, they are already in the same set.
        if (sz[rt_u] < sz[rt_v])swap(rt_u, rt_v); // Ensure that the smaller set (in terms of size) is merged into the larger one.
        // Merge set of 'rt_v' into set of 'rt_u' and update the size of 'rt_u'.
        par[rt_v] = rt_u;
        sz[rt_u] += sz[rt_v];
    }

    // This function finds the largest connected component size where elements have a common factor.
    int largestComponentSize(vector<int>& nums) {
        const int n = 1e5 + 10;  // Assumed upper bound for the range of numbers.
        int par[n];  // Parent array to represent the disjoint set.
        int sz[n];   // Size array to keep track of the size of each set.

        // Initialize each number's parent to itself and size to 1.
        for (int i = 1; i < n; i++) {
            par[i] = i;
            sz[i] = 1;
        }

        // For each number in 'nums', find its divisors and perform union operations
        // between the number and its divisors.
        for (auto ch : nums) {
            for (int i = 2; i <= sqrt(ch); i++) {
                if (ch % i == 0) {  // 'i' is a divisor of 'ch'
                    Union(par, sz, ch, i);       // Union 'ch' with its divisor 'i'
                    Union(par, sz, ch, ch / i);  // Union 'ch' with the other divisor 'ch / i'
                }
            }
        }

        unordered_map<int, int> occ;  // To count the occurrence of elements in each component.

        // For each number in 'nums', find its root and increment its occurrence in the map.
        for (auto ch : nums) {
            occ[find(par, ch)]++;
        }

        // Find the maximum size of any component.
        int ans = 1;
        for (auto ch : occ) {
            ans = max(ans, ch.second);  // Update 'ans' with the maximum component size.
        }

        return ans;  // Return the largest component size.
    }
};
