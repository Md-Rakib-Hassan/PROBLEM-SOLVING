//https://leetcode.com/problems/shuffle-the-array/


//using O(N) time and space

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int>ans;
        for(int i=0;i<n;i++){
           ans.push_back(nums[i]);
           ans.push_back(nums[n+i]);
        }
        return ans;


    }
};




//Using O(N) time and O(1) space using encoding

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int mx=*max_element(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            nums[i]=nums[i]*(mx+1)+nums[n+i];
        }
        for(int i=2*n-1;i>=0;i-=2){
            nums[i]=nums[(i-1)/2]%(mx+1);
            nums[i-1]=nums[(i-1)/2]/(mx+1);
        }
        return nums;
    }
};




//Using O(N) time and O(1) space using Bit Manipulation with In-Place Encoding


class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        for(int i=0;i<n;i++){
            nums[i]<<=10;
            nums[i]|=nums[n+i];
        }
        for(int i=2*n-1;i>=0;i-=2){
            nums[i]=nums[(i-1)/2]&(1<<10)-1;
            nums[i-1]=nums[(i-1)/2]>>10;
        }
        return nums;

    }
};