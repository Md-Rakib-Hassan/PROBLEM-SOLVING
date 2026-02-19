//https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

class Solution {
public:

    int lowerBound(vector<int>& nums,int l,int r, int target){
        while(l<r){
            int mid=l+(r-l)/2;
            if(nums[mid]<target)l=mid+1;
            else r=mid;
        }
        return l;
    }

    int upperBound(vector<int>& nums,int l,int r, int target){
        while(l<r){
            int mid=l+(r-l)/2;
            if(nums[mid]<=target)l=mid+1;
            else r=mid;
        }
        return l;
    }


    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans;
        int first= lowerBound(nums,0,nums.size(),target);
        int afterLast= upperBound(nums,0,nums.size(),target);
        if(first==afterLast) ans={-1,-1};
        else if(afterLast && nums[afterLast-1]==target)ans={first,afterLast-1};
        else ans={first,-1};
        return ans;
    }
};