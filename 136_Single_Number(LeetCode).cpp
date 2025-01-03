//https://leetcode.com/problems/single-number

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0; // Initialize result to 0
        
        // Iterate through each number in the array
        for (auto ch : nums) 
            ans ^= ch; // XOR operation to cancel out duplicate numbers
        
        return ans; // Return the unique number
    }
};
