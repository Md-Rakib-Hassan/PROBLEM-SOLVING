// https://leetcode.com/problems/stone-removal-game

class Solution {
public:
    bool canAliceWin(int n) {
        int turn = 0; // Tracks the number of turns taken (even for Alice, odd for Bob, alternating)
        int limit = 10; // Starting limit for the decrement value

        // Continue the game as long as 'n' is greater than or equal to the current limit
        while (n >= limit) {
            n -= limit--; // Decrease 'n' by the current limit, then decrement the limit
            turn++; // Increment the turn counter to alternate between players
        }

        // If the number of turns is odd, it's Alice's turn , otherwise it's Bob's turn and he loose. 
        return turn & 1;
    }
};
