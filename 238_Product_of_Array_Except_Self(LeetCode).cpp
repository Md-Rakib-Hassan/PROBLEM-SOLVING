// https://leetcode.com/problems/product-of-array-except-self


//Solution 1 that came to my head initially.

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // Create two auxiliary vectors: 
        // 'suf' for storing suffix products (product of elements to the right of the current index)
        // 'pre' for storing prefix products (product of elements to the left of the current index)
        vector<int> suf(nums.size()), pre;
        
        int sz = nums.size(); // Size of the input array

        // Step 1: Build the 'pre' vector (prefix products)
        for (int i = 0; i < sz; i++) {
            if (!i)  // For the first element, the prefix product is the element itself
                pre.push_back(nums[i]);
            else {
                // For every other element, the prefix product is the product of the element 
                // and the previous prefix product
                pre.push_back(nums[i] * pre[i - 1]);
            }
        }

        // Step 2: Build the 'suf' vector (suffix products)
        for (int i = sz - 1; i >= 0; i--) {
            if (i == sz - 1) // For the last element, the suffix product is the element itself
                suf[i] = nums[i];
            else {
                // For every other element, the suffix product is the product of the element 
                // and the next suffix product
                suf[i] = nums[i] * suf[i + 1];
            }
        }

        // Step 3: Compute the result by multiplying the prefix and suffix products
        for (int i = 0; i < sz; i++) {
            if (!i)  // For the first element, the result is just the suffix product of the next element
                nums[i] = suf[i + 1];
            if (i == sz - 1)  // For the last element, the result is just the prefix product of the previous element
                nums[i] = pre[i - 1];
            if (!i || i == sz - 1)  // Skip the first and last elements (already handled above)
                continue;
            // For all other elements, the result is the product of the prefix product (to the left) 
            // and the suffix product (to the right)
            nums[i] = pre[i - 1] * suf[i + 1];
        }
        
        return nums;  // Return the modified input array with the result
    }
};








//Solution 2 after watching others approch.


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int sz = nums.size(); // Get the size of the input array 'nums'
        
        // Initialize the answer vector 'ans' with size 'sz', where each element is 1
        vector<int> ans(sz, 1);
        
        // 'left' will store the product of all elements to the left of the current element
        int left = 1;
        
        // First pass: calculate the product of all elements to the left of each element
        for (int i = 0; i < sz; i++) {
            ans[i] *= left;  // Update the current element in 'ans' with the product from the left
            left *= nums[i]; // Update 'left' to include the current element of 'nums'
        }

        // 'right' will store the product of all elements to the right of the current element
        int right = 1;
        
        // Second pass: calculate the product of all elements to the right of each element
        for (int i = sz - 1; i >= 0; i--) {
            ans[i] *= right;  // Update the current element in 'ans' with the product from the right
            right *= nums[i]; // Update 'right' to include the current element of 'nums'
        }
        
        // Return the final 'ans' vector, which now contains the product of all elements except self
        return ans;
    }
};
