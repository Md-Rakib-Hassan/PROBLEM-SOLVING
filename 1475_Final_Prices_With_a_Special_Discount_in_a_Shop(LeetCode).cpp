// https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop

class Solution {
public:
      vector<int> finalPrices(vector<int>& prices) {
        // Loop through each price in the array
        for(int i = 0; i < prices.size(); i++) {
            // Inner loop to find the first subsequent price less than or equal to the current price
            for(int j = i + 1; j < prices.size(); j++) {
                // Check if the next item's price is less than or equal to the current item's price
                if(prices[i] >= prices[j]) {
                    // Apply the discount by subtracting the next item's price
                    prices[i] -= prices[j];
                    // Exit the inner loop after finding the first qualifying discount
                    break;
                }
            }
        }
        
        // Return the updated prices vector after applying all discounts
        return prices;
    }
};
