//https://leetcode.com/problems/fibonacci-number

class Solution {
public:
    int fib(int n) {
        // Base case: if n is 0, the Fibonacci number is 0.
        if(!n) return 0;
        
        // Initialize the first two Fibonacci numbers: F(0) = 0 and F(1) = 1.
        int l1 = 0, l2 = 1;
        
        // Iterate n - 1 times to calculate the nth Fibonacci number.
        for(int i = 0; i < n - 1; i++) {
            // Store the current value of l2 temporarily.
            int tmp = l2;
            
            // Update l2 to the next Fibonacci number by adding l1 and l2.
            l2 += l1;
            
            // Update l1 to the previous value of l2 (stored in tmp).
            l1 = tmp;
        }
        
        // Return the nth Fibonacci number.
        return l2;
    }
};
