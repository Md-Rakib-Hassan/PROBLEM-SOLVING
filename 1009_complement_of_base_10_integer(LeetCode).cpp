//https://leetcode.com/problems/complement-of-base-10-integer/

//Time complexity O(LogN) by alter all the bit

class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0)return 1;
        int tmp=n,i=0;
        while(tmp){
            n^=1<<i++;
            tmp>>=1;
        }
        return n;
    }
};



//Time complexity O(LogN) by bit masking

class Solution {
public:
    int bitwiseComplement(int n) {
        uint32_t mask=0xFFFFFFFF;
        int tmp=n;
        do{
            mask<<=1;
            tmp>>=1;
        }while(tmp);
        return ~n&~mask;
    }
};



//Time complexity O(1)

class Solution {
public:
    int bitwiseComplement(int n) {
        int mask=n|1;
        for(int i=0;i<=4;i++){
            mask|=mask>>(1<<i);
        }
        return ~n&mask;
    }
};

