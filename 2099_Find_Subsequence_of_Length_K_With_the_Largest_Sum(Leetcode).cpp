//https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        // 'ans' will store the top k largest elements (unordered)
        // 'num2' is a copy of the original array to maintain the original order
        // 'sub' will store the final result (top k elements in original order)
        vector<int> ans, num2 = nums, sub;

        // Sort the array in descending order to get the top k largest elements
        sort(nums.begin(), nums.end(), [](int &a, int &b) { return a > b; });

        // Store the top k largest elements into 'ans'
        for (int i = 0; i < k; i++) {
            ans.push_back(nums[i]);
        }

        // Iterate through the original array 'num2'
        for (auto ch : num2) {
            // Check if the current element is one of the top k elements
            auto it = find(ans.begin(), ans.end(), ch);
            // If found and we haven't collected k elements yet
            if (it != ans.end() && sub.size() < k) {
                // Add to result while maintaining the original order
                sub.push_back(*it);
                // Remove it from 'ans' to handle duplicates correctly
                ans.erase(it);
            }
        }

        // Return the final subsequence of k largest elements in original order
        return sub;
    }
};
