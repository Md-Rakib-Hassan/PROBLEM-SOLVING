//https://leetcode.com/problems/count-dominant-indices

class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        vector<int>avg;
        int sum=0,ans=0;
        for(int i=nums.size()-1;i>=0;i--){
            sum+=nums[i];
            avg.push_back(sum/(nums.size()-i));
        }
        reverse(avg.begin(),avg.end());
        for(int i=0; i<nums.size()-1;i++){
            if(nums[i]>avg[i+1])ans++;
        }
        return ans;
    }
};