//https://leetcode.com/problems/find-the-duplicate-number/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast=0, slow=0;
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        }while(nums[fast]!=nums[slow]);
        fast=0;
        while(nums[fast]!=nums[slow]){
            slow=nums[slow];
            fast=nums[fast];
        }

        return nums[slow];
        
    }
};