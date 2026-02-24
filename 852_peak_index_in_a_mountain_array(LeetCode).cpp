//https://leetcode.com/problems/peak-index-in-a-mountain-array

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l=0,r=arr.size()-1;

        while(l<=r){
            int m=l+(r-l+1)/2;
            if(arr[m]>arr[m-1] && arr[m]>arr[m+1])return m;
            else if(arr[m+1]>arr[m])l=m+1;
            else if(arr[m-1]>arr[m])r=m-1;
        }
        return 0;
    }
};