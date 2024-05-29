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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* first = head;
        ListNode* second = head;
        ListNode* temp = head;
        
        // Calculate the length of the list
        int n = 0;
        while (temp != NULL) {
            n++;
            temp = temp->next;
        }
        
        // Find the k-th node from the beginning
        for (int i = 1; i < k; i++) {
            first = first->next;
        }
        
        // Find the k-th node from the end
        temp = head;
        for (int i = 1; i <= n - k; i++) {
            second = second->next;
        }
        
        // Swap the values of the k-th node from the beginning and end
        int val = first->val;
        first->val = second->val;
        second->val = val;
        
        return head;
    }
};
