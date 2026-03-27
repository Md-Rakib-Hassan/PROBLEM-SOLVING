//https://leetcode.com/problems/coin-change-ii

class Solution {
public:
int dp[5005][302];

    int combi(int amount,int idx, vector<int>& coins){
        if(amount==0)return 1;
        if(idx==coins.size())return 0;
        if(amount<0)return 0;
        if(dp[amount][idx]!=-1)return dp[amount][idx];
        int ans=0;
       
        ans+=combi(amount-coins[idx],idx,coins);
        ans+=combi(amount,idx+1,coins);
        
        return dp[amount][idx]=ans;
    }


    int change(int amount, vector<int>& coins) {
        memset(dp,-1,sizeof(dp));
        return combi(amount,0,coins);
    }
};