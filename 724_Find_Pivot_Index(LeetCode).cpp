//https://leetcode.com/problems/find-pivot-index

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> prefix, suffix; // Vectors to store prefix sums and suffix sums
        int n = nums.size(); // Get the size of the input vector

        // Calculate prefix sums
        prefix.push_back(nums[0]); // Initialize prefix with the first element
        for (int i = 1; i < n; i++) {
            prefix.push_back(prefix.back() + nums[i]); // Add current element to the last prefix sum
        }

        // Calculate suffix sums
        suffix.push_back(nums.back()); // Initialize suffix with the last element
        for (int i = n - 2; i >= 0; i--) {
            suffix.push_back(suffix.back() + nums[i]); // Add current element to the last suffix sum
        }
        reverse(suffix.begin(), suffix.end()); // Reverse sums to get actual suffix sum

        // Find the pivot index
        for (int i = 0; i < n; i++) {
            if (prefix[i] == suffix[i]) return i; // If prefix sum equals suffix sum, return the current index
        }

        return -1; // Return -1 if no pivot index is found
    }
};
