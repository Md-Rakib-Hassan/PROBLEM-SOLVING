//https://leetcode.com/problems/power-of-two

//Solutions 1
class Solution {
public:
    bool isPowerOfTwo(int n) {
        // If 'n' is zero, return false because 0 is not a power of two
        if(!n) return false;

        // Calculate the base-2 logarithm of 'n'. 
        // If 'n' is a power of two, its logarithm base-2 should be an integer.
        double num = log2(n);

        // Check if 'num' is an integer by comparing it to its floor value.
        // If they are equal, it means 'n' is a power of two; otherwise, it is not. and for nagetive nan==nan will be false
        return num == floor(num);
    }
};


//Solutions 2

class Solution {
public:
    bool isPowerOfTwo(int n) {
        // A number 'n' is a power of two if:
        // 1. 'n' is positive (greater than 0).
        // 2. The binary representation of 'n' has exactly one '1' bit.
        //    The expression 'n & (n - 1)' checks this:
        //    - For powers of two, 'n' in binary has a single '1' bit and all other bits are '0'.
        //    - Subtracting 1 from 'n' flips all the bits after the rightmost '1'.
        //    - So, 'n & (n - 1)' will be 0 for powers of two (since there's no overlap in set bits).
        //    - If 'n' is not a power of two, this expression will be non-zero.
        return (n > 0 && !(n & (n - 1)));
    }
};
