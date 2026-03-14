//https://leetcode.com/problems/minimum-capacity-box

class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int ans=-1;
        for(int i=0;i<capacity.size();i++){
            if(capacity[i]>=itemSize ){
                if(ans==-1)ans=i;
                else if (min(capacity[ans],capacity[i])==capacity[i] && capacity[ans]!=capacity[i] ){
                    ans=i;
                };
            }
        }
        return ans;
    }
};