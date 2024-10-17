//https://leetcode.com/problems/integer-to-roman

class Solution {
public:
    string intToRoman(int num) {
        // A vector of pairs where each pair contains an integer and its corresponding Roman numeral representation.
        // The pairs are ordered from largest to smallest for easy conversion.
        vector<pair<int, string>> v{
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
            {90, "XC"},  {50, "L"},   {40, "XL"}, {10, "X"},   {9, "IX"},
            {5, "V"},    {4, "IV"},   {1, "I"},
        };
        
        string roman = "";  // This will store the resulting Roman numeral.
        int i = 0;          // Iterator for the vector of pairs.
        
        // While the number is not 0, convert it to the Roman numeral representation.
        while (num) {
            // Determine how many times the current Roman numeral can fit into the remaining number.
            int occ = num / v[i].first;
            
            // Subtract the equivalent value of the Roman numeral that has been added to the result. we also can do modulus operation
            num -= occ * v[i].first;
            
            // Append the Roman numeral to the result for each occurrence.
            for (int j = 0; j < occ; j++) {
                roman += v[i].second;
            }
            
            // Move to the next Roman numeral in the list.
            i++;
        }
        
        return roman;  // Return the final Roman numeral string.
    }
};
