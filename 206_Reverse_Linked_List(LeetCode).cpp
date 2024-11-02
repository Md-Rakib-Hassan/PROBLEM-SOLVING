// https://leetcode.com/problems/reverse-linked-list

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
    ListNode* reverseList(ListNode* head) {
        // Base case: if the list is empty or has one node, return the head
        if(!head || !head->next) return head;
        
        // Initialize pointers to reverse the list
        ListNode* prev = head; 
        ListNode* immediate = head->next;
        ListNode* tmp = immediate->next;
        
        // Break the initial link
        prev->next = nullptr;
        
        // Iterate through the list and reverse the links
        while(tmp) {
            immediate->next = prev; // Reverse the immediate previous link
            prev = immediate;       // Move prev to the immediate node
            immediate = tmp;        // Move immediate to the current node
            tmp = tmp->next;        // Move tmp to the next node
        }
        
        // Finalize the reversal by linking the last node
        immediate->next = prev;

        // Return the new head of the reversed list
        return immediate;
    }
};
