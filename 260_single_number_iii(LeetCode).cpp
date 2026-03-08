//https://leetcode.com/problems/single-number-iii/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int ans=0;
        for(int n:nums)ans^=n;
        int bitdif=1;

        while(!(ans&bitdif)){
            bitdif<<=1;
        }
        int a=0,b=0;
        for(int n:nums){
            if(n&bitdif)a^=n;
            else b^=n;
        }
        return {a,b};

    }
};