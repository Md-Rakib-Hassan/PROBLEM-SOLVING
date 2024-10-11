//https://leetcode.com/problems/minimum-size-subarray-sum

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // Initialize two pointers i and j to define the sliding window
        // sum keeps track of the sum of the current window
        // ans stores the minimum length of the subarray, initialized to a large value (INT_MAX)
        int i = 0, j = 0, sum = 0, ans = INT_MAX;
        
        // Outer loop to expand the window by moving the right pointer (i)
        while (i < nums.size()) {
            // Add the current element to the window sum
            sum += nums[i];
            
            // Inner loop to shrink the window from the left (move j) while the sum is >= target
            while (sum >= target) {
                // Update the answer to be the minimum length of the current valid subarray
                ans = min(ans, i - j + 1);
                
                // Remove the leftmost element (nums[j]) from the sum and move j to shrink the window
                sum -= nums[j];
                j++;
            }
            
            // Move the right pointer to expand the window
            i++;
        }
        
        // If no valid subarray was found, return 0. Otherwise, return the minimum length found.
        return ans == INT_MAX ? 0 : ans;
    }
};
