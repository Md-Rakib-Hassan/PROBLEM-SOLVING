//https://leetcode.com/problems/construct-uniform-parity-array-ii/

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int odd=0,even=0,mn=nums1[0];
        for(int n:nums1){
            if(n&1)odd++;
            else even++;
            mn=min(mn,n);
        }
        if(mn&1)return true;
        else{
            if(odd==0)return true;
        }

        return false;
    }
};