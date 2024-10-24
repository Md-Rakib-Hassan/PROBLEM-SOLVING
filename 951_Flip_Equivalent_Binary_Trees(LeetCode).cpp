//https://leetcode.com/problems/flip-equivalent-binary-trees

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
    // Struct to store information about a tree node and its parent, used for tracking node type (root1 or root2)
    struct trio{
        TreeNode* parents;  // Pointer to the parent node
        TreeNode* child;    // Pointer to the current child node
        int type;           // Type indicator to distinguish nodes from root1 (type 1) and root2 (type 2)
    };


    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        // Queue to store nodes and their relationships as 'trio' for both trees
        queue<trio>q;

        // Initialize the queue with root nodes of both trees
        q.push({root1, root1, 1}); // Enqueue the root of tree1 with type 1
        q.push({root2, root2, 2}); // Enqueue the root of tree2 with type 2

        // Variable to store the result, initially set to true (assume trees are flip equivalent)
        bool ans = true;

        // Loop until the queue is empty
        while(!q.empty()){
            int sz = q.size();  // Get the current queue size
            unordered_map<int, int> m1, m2;  // Maps to store child-parent relationships for both trees
            
            // Process all nodes at the current level
            for(int i = 0; i < sz; i++){
                auto crnt = q.front();  // Get the front element from the queue
                q.pop();  // Remove the element from the queue
                
                // If the current node has no child, skip to the next node
                if(!(crnt.child)) continue;

                // If the node belongs to the first tree, update map m1 with its child and parent values
                if(crnt.type == 1) m1[crnt.child->val] = crnt.parents->val;
                // If the node belongs to the second tree, update map m2 with its child and parent values
                else m2[crnt.child->val] = crnt.parents->val;

                // Push the left and right children of the current node onto the queue
                q.push({crnt.child, crnt.child->left, crnt.type});
                q.push({crnt.child, crnt.child->right, crnt.type});
            }

            // If the child-parent mappings between the two trees at the current level don't match, set ans to false and exit
            if(m1 != m2){
                ans = false;
                break;
            }
        }

        // Return the result indicating whether the two trees are flip equivalent
        return ans;
    }
};
