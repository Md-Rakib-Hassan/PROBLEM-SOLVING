// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        //Reorder the elements in the array 
        for(int i = 0; i < nums.size(); i++) {
            // Place each number in its correct position (i.e., nums[i] should be at index nums[i]-1)
            while(nums[i] != nums[nums[i] - 1])
                swap(nums[i], nums[nums[i] - 1]);
        }

        vector<int> ans;
        // Identifying numbers that are not in their correct positions
        for(int i = 0; i < nums.size(); i++) {
            // If the number at index i is not i + 1, then i + 1 is missing
            if(i + 1 != nums[i]) ans.push_back(i + 1);
        }

        // Return the list of missing numbers
        return ans;
    }
};
