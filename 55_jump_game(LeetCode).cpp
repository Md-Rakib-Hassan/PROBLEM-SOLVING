//https://leetcode.com/problems/jump-game

///////  time: O(n^2)     space: O(n)   Dynamic Programming Approach////////////

class Solution {
public:
    int dp[10005];
    bool reached=false;
    bool solve(vector<int>& nums,int idx){
        if(idx>=nums.size()-1){
            reached=true;
            return true;
            }
        if(dp[idx]!=-1)return dp[idx];
        bool ans=false;

        if(!reached){
            for(int i=nums[idx];i>=1;i--){
            ans|=solve(nums,idx+i);
            }
        }
        return dp[idx]=ans;
    }

    bool canJump(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        solve(nums,0);
        return reached;
    }
};





////////////time: O(n)   Space: O(1) Greedy Approach/////////


class Solution {
public:
    bool canJump(vector<int>& nums) {
        int mxjmp=0,sz=nums.size();
        for(int i=0;i<sz;i++){
            if(mxjmp<i)return false;
            mxjmp=max(mxjmp,i+nums[i]);
        }
        return true;
    }
};