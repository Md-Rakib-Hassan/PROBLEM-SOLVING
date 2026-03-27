//https://leetcode.com/problems/coin-change


class Solution {
public:
    int arr[10050];
    int combi(vector<int>& coins, int amount){
        if(amount==0)return 0;
        if(arr[amount]!=-1)return arr[amount];
        int ans=INT_MAX;
        for(int coin:coins){
          if(amount-coin>=0)ans=min(ans+0ll,combi(coins,amount-coin)+1ll);
        }
        return arr[amount]=ans;
    }

    int coinChange(vector<int>& coins, int amount) {
        memset(arr,-1,sizeof(arr));
        int ans=combi(coins,amount);
        return ans==INT_MAX?-1:ans;
    }
};