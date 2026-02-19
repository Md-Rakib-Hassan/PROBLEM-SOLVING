//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0,r=nums.size()-1,ans=nums[0];
        while(l<=r){
            if(nums[l]<nums[r]){
                ans=min(ans,nums[l]);
                break;
            }
            int m=l+(r-l)/2;
            ans=min(ans,nums[m]);
            if(nums[m]>=nums[l])l=++m;
            else r=--m;

        }
        return ans;
    }
};