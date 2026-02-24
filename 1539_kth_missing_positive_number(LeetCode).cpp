//https://leetcode.com/problems/kth-missing-positive-number

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        if(k<arr[0])return k;
        int l=0,r=arr.size()-1;
        int closest=0;
        while(l<=r){
            int m=l+(r-l)/2;
            if(arr[m]-m<=k){
                closest=m;
                l=m+1;
            }
            else r=m-1;
        }
        return arr[closest]+(k-(arr[closest]-closest-1));
    }
};