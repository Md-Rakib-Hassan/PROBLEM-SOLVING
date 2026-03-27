//https://leetcode.com/problems/set-mismatch

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n= nums.size(),dup,miss;
        int arr[n+1];
        memset(arr,0,sizeof(arr));
        for(int num:nums)arr[num]++;
        for(int i=1;i<=n;i++){
            if(arr[i]==0)miss=i;
            if(arr[i]==2)dup=i;
        }
        return {dup,miss};
    }
};