//https://leetcode.com/problems/remove-duplicates-from-sorted-list

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        // If the list is empty, return null
        if (!head)return head;
        
        // Initialize two pointers: prev at the head, and crnt at the second node
        ListNode* prev = head;
        ListNode* crnt = head->next;

        // If there is only one node in the list, return the head
        if (!crnt)return head;

        // Traverse the list
        while (crnt) {
            // Skip over nodes that have the same value as prev
            while (crnt && crnt->val == prev->val) {
                crnt = crnt->next;
            }

            // Link prev to the first non-duplicate node found
            if (prev) {
                prev->next = crnt;
                prev = prev->next;  // Move prev to the next unique node
            }

            // Move crnt to the next node for comparison
            if (crnt) crnt = crnt->next;
        }
        
        // Return the modified list with duplicates removed
        return head;
    }
};
