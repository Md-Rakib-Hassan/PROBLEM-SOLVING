//https://leetcode.com/problems/jewels-and-stones

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        // Map to store each jewel type and track its presence
        map<char, int> jewel;
        
        // Iterate over each character in jewels and increment its count in the map
        for(auto ch : jewels)jewel[ch]++;
        
        // Variable to keep track of the number of jewels found in stones
        int having_number_of_jewels = 0;
        
        // Iterate over each character in stones
        // If the stone character is a jewel, increment the count by 1
        for(auto ch : stones)having_number_of_jewels += jewel[ch];
        
        // Return the total count of jewels found in stones
        return having_number_of_jewels;
    }
};
