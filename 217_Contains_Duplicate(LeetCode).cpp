// https://leetcode.com/problems/contains-duplicate


class Solution {
public:

    bool containsDuplicate(vector<int>& nums) {
        // Create a set from the elements of the vector. A set automatically removes duplicates.
        // Compare the size of the original vector with the size of the set.
        // If the sizes are different, it means there were duplicates in the original vector.
        return nums.size() > set<int>(nums.begin(), nums.end()).size();
    }
};
