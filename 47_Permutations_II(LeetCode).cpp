//https://leetcode.com/problems/permutations-ii

class Solution {
public:

    // Helper function to generate all permutations and store unique permutations in the map
    void perm(vector<int>& nums, map<vector<int>,int>&mp, int sz, int idx) {

        // Base case: if idx reaches the size of the nums array, add the current permutation to the map
        if (idx == sz) {
            mp[nums]=1; // The map is used to store unique permutations, ignoring duplicates
            return;
        }

        // Loop through each element from idx to sz, swapping elements to generate permutations
        for (int i = idx; i < sz; i++) {
            swap(nums[i], nums[idx]);   // Swap the current element with the idx element
            perm(nums, mp, sz, idx + 1); // Recursively call perm with the next index
            swap(nums[i], nums[idx]);   // Swap back to restore the original array (backtracking)
        }
    }

    // Main function to return all unique permutations of the input nums array
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        vector<vector<int>> ans;       // Stores the final list of unique permutations
        map<vector<int>,int> mp;       // Map to ensure only unique permutations are stored
        perm(nums, mp, nums.size(), 0); // Call the helper function to generate permutations
        
        // Transfer all unique permutations from the map to the ans vector
        for(auto ch: mp) ans.push_back(ch.first);
        
        return ans; // Return the list of unique permutations
    }
};
