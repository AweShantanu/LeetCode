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
    ListNode* mergeTwo(ListNode* l1,ListNode* l2)
    {
        if(l1==NULL)
        {
            return l2;
        }
        if(l2==NULL)
            return l1;
        
        if(l1->val <= l2->val)
        {
            l1->next=mergeTwo(l1->next,l2);
            return l1;
        }
        else{
            l2->next=mergeTwo(l1,l2->next);
            return l2;
                
        }
    }
    ListNode* toroAndZoro(int start,int end,vector<ListNode*>& lists)
    {
        if(start>end)
        {
            return NULL;
        }
        if(start==end)
        {
            return lists[start];
        }
        int mid=(start+end)/2;
        ListNode* left=toroAndZoro(start,mid,lists);
        ListNode* right=toroAndZoro(mid+1,end,lists);
        return mergeTwo(left,right);
        
        
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        return toroAndZoro(0,n-1,lists);
    }
};