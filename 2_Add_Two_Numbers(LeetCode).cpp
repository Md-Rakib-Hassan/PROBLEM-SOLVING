//https://leetcode.com/problems/add-two-numbers
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
    // Function to add two numbers represented by linked lists
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;  // Variable to store the carry from the sum of two digits
        ListNode* head = new ListNode(0);  // Dummy node to act as the head of the resulting linked list
        ListNode* tail = head;  // Pointer to track the end of the result list

        // Continue looping until both lists have been fully traversed
        while (!(l1 == nullptr && l2 == nullptr)) {
            int sum = 0;  // Variable to store the sum of the digits from l1, l2, and the carry
            
            // If l1 is not null, add its value to sum and move to the next node
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }

            // If l2 is not null, add its value to sum and move to the next node
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            sum += carry;  // Add the carry from the previous addition
            carry = sum / 10;  // Calculate the new carry (if the sum is 10 or more)
            
            // If there is a carry, reduce sum to the digit that will be stored in the node
            if (carry) sum = sum % 10;
            
            // Create a new node with the computed sum and add it to the result list
            tail->next = new ListNode(sum);
            tail = tail->next;  // Move the tail pointer to the new last node
        }

        // After traversing both lists, if there is a remaining carry, add it as a new node
        if (carry) {
            ListNode* Last = new ListNode(carry);
            tail->next = Last;
        }

        return head->next;  // Return the next node of the dummy head, which is the actual start of the result list
    }
};