// https://leetcode.com/problems/rotate-array

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int sz = nums.size();  // Get the size of the array

        // If k is greater than the size of the array, we only need to rotate by k % sz because after rotated the array amount of nums.size()*xxx will be given the same array
        k = k % sz;

        // Reverse the first part of the array (from the beginning to the element before sz-k)
        reverse(nums.begin(), nums.end() - k);
        
        // Reverse the second part of the array (from the element sz-k to the end)
        reverse(nums.begin() + sz - k, nums.end());
        
        // Reverse the entire array to achieve the desired rotation
        reverse(nums.begin(), nums.end());
    }
};
