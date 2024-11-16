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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head; // Edge case
        
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;

        while (even && even->next) {
            odd->next = even->next; // Connect odd nodes
            odd = odd->next;        // Move odd pointer
            
            even->next = odd->next; // Connect even nodes
            even = even->next;      // Move even pointer
        }

        odd->next = evenHead; // Reconnect even list to odd list
        return head;
    }
};
