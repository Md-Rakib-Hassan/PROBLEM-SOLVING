//https://leetcode.com/problems/add-digits

class Solution {
public:
    int addDigits(int num) {
        // If the number is 0, the result is 0 (special case for zero).
        if(num == 0) return 0;

        // If the number is divisible by 9, the result is 9 (handling numbers like 9, 18, 27, etc.).
        if(num % 9 == 0) return 9;

        // Otherwise, return the remainder when num is divided by 9 (digital root calculation).
        return num % 9;
    }
};
