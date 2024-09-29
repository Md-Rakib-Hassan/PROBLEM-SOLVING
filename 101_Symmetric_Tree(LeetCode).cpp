/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // Function to check if a binary tree is symmetric (mirror image of itself)
    bool isSymmetric(TreeNode* root) {
        // A tree with no root is considered symmetric
        if(!root) return true;

        // Two queues to perform a level-order traversal
        queue<TreeNode*> q1, q2;
        
        // Start by adding the left and right child of the root to respective queues
        q1.push(root->left);
        q2.push(root->right);

        // Continue the process while both queues are not empty
        while(!q1.empty() && !q2.empty()) {
            // Retrieve the front node from each queue
            auto crnt1 = q1.front();
            auto crnt2 = q2.front();
            
            // Remove the front node from each queue
            q1.pop();
            q2.pop();
            
            // If both nodes are null, continue to the next iteration (they are symmetric at this level)
            if(!crnt1 && !crnt2) continue;

            // If one node is null and the other isn't, the tree is not symmetric
            if(!crnt1 || !crnt2) return false;

            // If the values of the two nodes don't match, the tree is not symmetric
            if(crnt1->val != crnt2->val) return false;

            // Enqueue the children of both nodes in opposite order for symmetry comparison
            // Left child of the first tree with the right child of the second tree
            q1.push(crnt1->left);
            q1.push(crnt1->right);
            q2.push(crnt2->right);
            q2.push(crnt2->left);
        }
        
        // If the loop completes without returning false, the tree is symmetric
        return true; 
    }
};
