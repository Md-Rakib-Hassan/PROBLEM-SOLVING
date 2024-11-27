// https://leetcode.com/problems/special-array-i

class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        // An array with a single element is trivially special.
        if (nums.size() == 1)
            return true;

        // For an array of size 2, it is special if the two elements have different parity.
        if (nums.size() == 2 && (nums[0] & 1) != (nums[1] & 1))
            return true;
        else if (nums.size() == 2) // If the elements have the same parity, it's not special.
            return false;

        // For arrays with more than two elements, iterate through the array to verify conditions.
        bool ans = true;
        for (int i = 0; i < nums.size() - 2; i++) {
            // Check if the parity alternates correctly:
            // - nums[i] and nums[i + 2] must have the same parity.
            // - nums[i + 1] must have a different parity compared to nums[i].
            if (!(((nums[i] & 1) == (nums[i + 2] & 1)) && ((nums[i] & 1) != (nums[i + 1] & 1)))) {
                ans = false; // If any condition fails, the array is not special.
                break;
            }
        }
        // Return the result after verifying all conditions.
        return ans;
    }
};
