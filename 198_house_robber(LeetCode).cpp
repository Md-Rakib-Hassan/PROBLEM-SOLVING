//https://leetcode.com/problems/house-robber

class Solution {
public:
    int dp[105];
    int solve(int i,vector<int>& nums){
        if(i>=nums.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int ans=INT_MIN;
        ans=max(ans,solve(i+2,nums)+nums[i]);
        ans=max(ans,solve(i+1,nums));
        return dp[i]=ans;
    }

    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(0,nums);
    }
};