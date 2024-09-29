//https://leetcode.com/problems/same-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;                   // Value of the node
 *     TreeNode *left;           // Pointer to the left child
 *     TreeNode *right;          // Pointer to the right child
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {} // Default constructor
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} // Constructor with value
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {} // Constructor with value and children
 * };
 */

class Solution {
public:
    // Function to check if two binary trees are the same
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Queues to hold the nodes of each tree for level-order traversal
        queue<TreeNode*> qt, qt2;
        qt.push(p);     // Push root of the first tree into the queue
        qt2.push(q);    // Push root of the second tree into the queue

        // Continue processing while both queues are not empty
        while (!qt.empty() && !qt2.empty()) {
            // Get the front node from both queues
            auto crnt = qt.front();
            auto crnt2 = qt2.front();
            qt.pop();     // Remove the front node from the first queue
            qt2.pop();    // Remove the front node from the second queue
            
            // If both nodes are null, they are equivalent at this level
            if (crnt == NULL && crnt2 == NULL)
                continue;
            // If one node is null and the other is not, the trees are not the same
            if (crnt == NULL || crnt2 == NULL)
                return false;
            // If the values of the current nodes do not match, the trees are not the same
            if (crnt->val != crnt2->val)
                return false;

            // Push left and right children of the current nodes into their respective queues
            qt.push(crnt->left);
            qt.push(crnt->right);
            qt2.push(crnt2->left);
            qt2.push(crnt2->right);
        }
        // If we exit the loop, both trees have been checked and are the same
        return true;
    }
};
