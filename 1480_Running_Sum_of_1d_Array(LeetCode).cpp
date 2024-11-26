// https://leetcode.com/problems/running-sum-of-1d-array

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        // Loop through the array starting from the second element (index 1)
        for (int i = 1; i < nums.size(); i++) {
            // Add the previous element's value to the current element
            nums[i] += nums[i - 1];
        }
        // Return the modified array with running sums
        return nums;
    }
};
