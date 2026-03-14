//https://leetcode.com/problems/find-the-smallest-balanced-index


class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        unsigned long long product=1,mxsum=0;
        if(nums.size()==2 && nums[0]==1)return 1;
        
        for(int x:nums)mxsum+=x;
            mxsum-=nums[nums.size()-1];

        for(int i=nums.size()-1;i>=0;i--){
            if(product>mxsum/nums[i])break;
            product*=(nums[i]*1ll);
            if(i-1>=0)mxsum-=nums[i-1];
            if(mxsum==product)return i-1;
        }

        return -1;
        
        

        
    }
};