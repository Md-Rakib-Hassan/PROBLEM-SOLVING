//https://leetcode.com/problems/minimum-cost-for-tickets


///////////Time complexity : O(NLogN)//////// 

class Solution {
public:
int dp[367];

    int idx(vector<int>& days,int day){
        return upper_bound(days.begin(),days.end(),day)-days.begin();
    }

    int solve(vector<int>& days, vector<int>& costs,int i){
        if(i>=days.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int ans=INT_MAX;
        for(int j=0;j<3;j++){
            int jump=1;
            if(j==1)jump=7;
            if(j==2)jump=30;
            ans=min(ans+0ll, (long long)solve(days,costs,idx(days,days[i]+jump-1))+costs[j]+0ll);
        }
        return dp[i]=ans;

    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp,-1,sizeof(dp));
        return solve(days,costs,0);
    }
};









///////////Time complexity : O(N)///////////




class Solution {
public:
int dp[367];

    int solve(vector<int>& days, vector<int>& costs,int i){
        if(i>=days.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int ans=INT_MAX;
        for(int j=0;j<3;j++){
            int jump=1;
            if(j==1)jump=7;
            if(j==2)jump=30;

            int pass_end=days[i]+jump-1;
            int idx_next_day=i;
            while(idx_next_day<days.size() && days[idx_next_day]<=pass_end)idx_next_day++;

            ans=min(ans+0ll, (long long)solve(days,costs,idx_next_day)+costs[j]+0ll);
        }
        return dp[i]=ans;

    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp,-1,sizeof(dp));
        return solve(days,costs,0);
    }
};