//https://leetcode.com/problems/subsets/

class Solution {
public:
    vector<vector<int>>sub(vector<vector<int>>&ans,vector<int>&v,vector<int>&c ,int i=0){
        if(i==v.size()){
            ans.push_back(c);
            return ans;
        }
        c.push_back(v[i]);
        sub(ans,v,c,i+1);
        c.pop_back();
        sub(ans,v,c,i+1);
        return ans;
    }


    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>c;
        return sub(ans,nums,c);
    }
};