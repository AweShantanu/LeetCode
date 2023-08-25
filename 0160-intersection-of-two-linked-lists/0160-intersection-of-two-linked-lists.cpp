/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a=headA;
        ListNode* b=headB;
        while(a->next && b->next)
        {
            if(a==b)
            {
                return a;
            }
            a=a->next;
            b=b->next;
        }
        if(a->next==NULL && b->next==NULL && a!=b)
        {
            return 0;
        }
        
        if(a->next==0)
        {
            //matlab b bada hai a se
            int len=0;
            
            while(b->next!=NULL)
            {
                len++;
                b=b->next;
                
            }
            
            while(len--)
            {
                headB=headB->next;
                
            }
        }
        else {
            //matlab a bada hai 
            int len=0;
        
            while(a->next!=0)
            {
                len++;
                a=a->next;
                
            }
            
            while(len--)
            {
                headA=headA->next;
                
            }
        }
        while(headA!=headB)
        {
            headA=headA->next;
            headB=headB->next;
        }
        return headA;
    }
};