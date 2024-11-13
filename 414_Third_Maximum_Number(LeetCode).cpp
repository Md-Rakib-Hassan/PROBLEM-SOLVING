//https://leetcode.com/problems/third-maximum-number

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int sz = nums.size();         // Get the size of the input vector
        int inf = INT_MIN;            // Initialize 'inf' as the smallest integer value

        // Handle edge cases:
        if (sz == 1) return nums[0];                    // If there's only one element, return it
        if (sz == 2) return max(nums[0], nums[1]);      // If there are two elements, return the maximum

        // Initialize the three maximum variables to 'inf'
        int mx = inf, mx2 = inf, mx3 = inf;
        bool mx2_flag = false, mx3_flag = false;        // Flags to indicate if mx2 and mx3 are found

        // First loop: Find the largest number in the array and store it in 'mx'
        for (auto ch : nums) mx = max(mx, ch);

        // Second loop: Find the second largest number, ignoring the largest
        for (auto ch : nums) {
            if (ch == mx) continue;                     // Skip if the number is the same as 'mx'
            mx2 = max(mx2, ch);                         // Update 'mx2' with the max between 'mx2' and current number
            mx2_flag = true;                            // Set the flag to true as we found a valid second max
        }

        // Third loop: Find the third largest number, ignoring 'mx' and 'mx2'
        for (auto ch : nums) {
            if (ch == mx || ch == mx2) continue;        // Skip if the number is 'mx' or 'mx2'
            mx3 = max(mx3, ch);                         // Update 'mx3' with the max between 'mx3' and current number
            mx3_flag = true;                            // Set the flag to true as we found a valid third max
        }

        // Return the third maximum if it exists; otherwise, return the maximum
        return mx3_flag ? mx3 : mx;
    }
};
