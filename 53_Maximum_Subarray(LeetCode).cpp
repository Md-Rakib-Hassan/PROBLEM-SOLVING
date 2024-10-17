//https://leetcode.com/problems/maximum-subarray

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Initialize the max_sum and sum to the first element of the array
        int max_sum = nums[0], sum = nums[0];
        
        // Loop through the array starting from the second element
        for (int i = 1; i < nums.size(); i++) {
            // If the current sum is negative, reset it to 0 (start a new subarray)
            if (sum < 0) sum = 0;
            
            // Add the current element to sum
            sum += nums[i];
            
            // Update max_sum to be the maximum of the current max_sum and sum
            max_sum = max(max_sum, sum);
        }
        
        // Return the maximum sum found
        return max_sum;
    }
};
