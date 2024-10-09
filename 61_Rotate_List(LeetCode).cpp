//https://leetcode.com/problems/rotate-list

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
    ListNode* rotateRight(ListNode* head, int k) {
        // Base case: if k is 0 or the list is empty, return the original list
        if (!k || !head)
            return head;

        ListNode* tmp = head;
        ListNode* last_node;   // To store the last node of the list
        int list_length = 0;   // Variable to hold the length of the list

        // Traverse the list to calculate its length and get the last node
        while (tmp) {
            list_length++;
            if (!tmp->next) {  // If we are at the last node, save its pointer
                last_node = tmp;
            }
            tmp = tmp->next;
        }

        // Reduce k to a valid number by taking modulus with the list length
        k = k % list_length;

        tmp = head;
        for (int i = 0; i < list_length - k - 1; i++) {
            tmp = tmp->next;   // Move to the (list_length - k - 1)-th node
        }

        ListNode* new_head;    // Pointer for the new head after rotation

        // If the next node exists, rotate the list
        if (tmp->next) {
            new_head = tmp->next;         // Set new_head to the (list_length - k)-th node
            last_node->next = head;       // Make the last node point to the original head
            tmp->next = nullptr;          // Break the link to form the new end of the list
        }

        // Return the new head if rotation occurred, otherwise return the original head
        return new_head ? new_head : head;
    }
};
