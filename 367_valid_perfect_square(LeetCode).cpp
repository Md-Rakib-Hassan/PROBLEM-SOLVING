//https://leetcode.com/problems/valid-perfect-square

class Solution {
public:
    bool isPerfectSquare(int num) {
        bool ans=false;
        long l=0, r=num;
        while(l<=r){
            long m=l+(r-l)/2;
            if(m*m==num){
                ans=true;
                break;
            }
            else if(m*m<num)l=m+1;
            else r=m-1;
        }
        return ans;
    }
};