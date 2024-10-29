//https://leetcode.com/problems/3sum-closest

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int sz = nums.size();
        // Sort the vector to enable two-pointer technique
        sort(nums.begin(), nums.end());
        
        // Initialize the closest difference and result with the sum of the first three elements
        int closestpre = abs(target - (nums[0] + nums[1] + nums[2]));
        int ans = nums[0] + nums[1] + nums[2];
        
        // Iterate through each element in nums to use as the first element in the sum
        for (int i = 0; i < sz; i++) {
            int j = i + 1, k = sz - 1;
            
            // Use two pointers to find the closest sum of three numbers
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                
                // Calculate the current closest difference
                int closest = min(abs(target - sum), abs(target - ans));
                
                // Update result if curent difference is closer then the previous difference
                if (closest != closestpre) {
                    ans = sum;
                    closestpre = closest;
                }
                
                // Move pointers based on the comparison of sum with target
                if (sum > target) {
                    k--; // Decrease the sum by moving the right pointer leftward
                }
                else {
                    j++; // Increase the sum by moving the left pointer rightward
                }
            }
        }
        
        // Return the closest sum found
        return ans;
    }
};
