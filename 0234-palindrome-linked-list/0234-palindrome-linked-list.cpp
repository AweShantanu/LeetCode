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
    ListNode* reverse(ListNode* head1)
    {
        ListNode* prev=NULL;
        ListNode* curr= head1;
        while(curr !=NULL)
        {
        ListNode* nextNode=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextNode;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!= NULL)
        {
            slow=slow->next;
            fast=fast->next;
            if(fast!=NULL)
            {
                fast=fast->next;
            }
        }
       
        slow=reverse(slow);
        
        ListNode* temp1=head;
        while(slow !=NULL)
        {
            if(slow->val != temp1->val)
            {
                //not a pallindrome
                return false;

            }
            else{
                //is a pallindrome , Therefore hamen aage badhana parega
                temp1=temp1->next;
                slow=slow->next;
            }

        }
        return true;
        
        
        
        
        
        
    }
};