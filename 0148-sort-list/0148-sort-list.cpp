class Solution {
public:
    // Function to merge two sorted linked lists
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy; // Temporary dummy node
        ListNode* tail = &dummy; // Tail pointer to form the merged list
        
        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        
        // Append the remaining nodes
        if (l1) tail->next = l1;
        if (l2) tail->next = l2;
        
        return dummy.next;
    }

    // Function to find the middle of the linked list
    ListNode* getMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    // Function to sort the linked list using merge sort
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head; // Base case: 0 or 1 node
        
        // Split the list into two halves
        ListNode* middle = getMiddle(head);
        ListNode* right = middle->next;
        middle->next = nullptr;
        
        // Recursively sort the two halves
        ListNode* left = sortList(head);
        right = sortList(right);
        
        // Merge the two sorted halves
        return merge(left, right);
    }
};
