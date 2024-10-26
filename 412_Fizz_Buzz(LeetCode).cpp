//https://leetcode.com/problems/fizz-buzz

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans; // Initialize a vector to store the results
        for(int i = 1; i <= n; i++) { // Loop from 1 to n
            // If 'i' is divisible by both 3 and 5, add "FizzBuzz" to the result
            if(i % 15 == 0) 
                ans.push_back("FizzBuzz");
            // If 'i' is divisible by 3 only, add "Fizz" to the result
            else if(i % 3 == 0) 
                ans.push_back("Fizz");
            // If 'i' is divisible by 5 only, add "Buzz" to the result
            else if(i % 5 == 0) 
                ans.push_back("Buzz");
            // If 'i' is not divisible by either 3 or 5, add the number as a string
            else 
                ans.push_back(to_string(i));
        }
        return ans; // Return the vector with results
    }
};
