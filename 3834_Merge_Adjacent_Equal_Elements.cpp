//https://leetcode.com/problems/merge-adjacent-equal-elements

class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        vector<long long>v;
        for(int i=0;i<nums.size();i++){
            long long cur=nums[i];
            while(v.size()&&v.back()==cur){
                v.pop_back();
                cur+=cur;
            }
            v.push_back(cur);
        }
     return v;   
    }
};