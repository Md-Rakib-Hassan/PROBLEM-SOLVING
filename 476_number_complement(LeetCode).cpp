//https://leetcode.com/problems/number-complement/

class Solution {
public:
    int findComplement(int num) {
        int tmp=num,i=0;
        while(tmp){
            num^=1<<i++;
            tmp>>=1;
        }
        return num;
    }
};