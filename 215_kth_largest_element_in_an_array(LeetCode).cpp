//https://leetcode.com/problems/kth-largest-element-in-an-array

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int sz=nums.size(), arr[20001];
        memset(arr,0,sizeof(arr));
        for(int i=0;i<sz;i++){
            arr[nums[i]+10000]++;
        }
        for(int i=20000;i>=0;i--){
            k-=arr[i];
            if(k<=0)return i-10000;
        }
        return -1;
    }
};