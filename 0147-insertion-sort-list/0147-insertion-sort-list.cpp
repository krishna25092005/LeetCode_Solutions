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
    ListNode* insertionSortList(ListNode* head) {
        // Create a dummy node that acts as the starting point of the sorted list
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        // `current` will be used to iterate over the unsorted part of the list
        ListNode* current = head;
        
        while (current != nullptr && current->next != nullptr) {
            // If the current node's value is greater than the next node's value, we need to reorder
            if (current->val > current->next->val) {
                ListNode* temp = current->next;  // The node to be inserted
                current->next = temp->next;      // Remove `temp` from the unsorted part
                
                // Now find the correct position to insert `temp` in the sorted part
                ListNode* pos = dummy;
                while (pos->next != nullptr && pos->next->val < temp->val) {
                    pos = pos->next;
                }
                
                // Insert `temp` in the sorted part
                temp->next = pos->next;
                pos->next = temp;
            } else {
                // No need to reorder, just move forward
                current = current->next;
            }
        }
        
        // The sorted list is in `dummy->next`
        return dummy->next;
    }
};
