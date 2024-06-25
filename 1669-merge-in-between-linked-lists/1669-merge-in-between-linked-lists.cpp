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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* left = list1;
        ListNode* right = list1;
        
        // Find the node just before position 'a'
        for (int i = 0; i < a - 1; ++i) {
            left = left->next;
        }
        
        // Find the node just after position 'b'
        for (int i = 0; i <= b; ++i) {
            right = right->next;
        }
        
        // Link the node just before 'a' to the head of 'list2'
        left->next = list2;
        
        // Traverse to the end of 'list2'
        ListNode* temp = list2;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        
        // Link the end of 'list2' to the node just after 'b'
        temp->next = right;
        
        // Return the modified 'list1'
        return list1;
    }
};
