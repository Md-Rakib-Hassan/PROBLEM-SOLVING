//https://leetcode.com/problems/permutations

class Solution {
public:
    // Helper function to generate all permutations recursively
    void perm(vector<int>& nums, vector<vector<int>>& ans, int sz, int idx) {
        // Base case: If the current index is equal to the size, a complete permutation is formed
        if (idx == sz) {
            ans.push_back(nums); // Add the current permutation to the result
            return;
        }

        // Loop through the array to generate all permutations
        for (int i = idx; i < sz; i++) {
            swap(nums[i], nums[idx]);  // Swap current element with the element at the current index
            perm(nums, ans, sz, idx + 1);  // Recursively call perm to generate further permutations
            swap(nums[i], nums[idx]);  // Backtrack by swapping the elements back to their original positions
        }
    }

    // Main function to initiate permutation generation
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;  // To store all permutations
        perm(nums, ans, nums.size(), 0);  // Call the recursive function starting from index 0
        return ans;  // Return the list of all permutations
    }
};
