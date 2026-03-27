//https://leetcode.com/problems/max-consecutive-ones

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cur=0,ans=0;
        for(int n:nums){
            if(n==1)ans=max(ans,++cur);
            else cur=0;
        }
        return ans;
    }
};