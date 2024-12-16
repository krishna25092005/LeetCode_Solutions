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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0); // Placeholder for the resulting list
        ListNode* current = dummyHead;
        int carry = 0;

        // Traverse through both linked lists
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;

            // Add the values from l1 and l2 if they exist
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            // Compute the new digit and the carry
            carry = sum / 10;
            int digit = sum % 10;

            // Append the new digit to the resulting linked list
            current->next = new ListNode(digit);
            current = current->next;
        }

        // Return the next node of dummyHead as the head of the result
        return dummyHead->next;
    }
};
