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
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int, ListNode*> mp;
        ListNode* dummy=new ListNode(0);
        mp[0]=dummy;
        dummy->next=head;
        int preSum=0;
        while(head!=NULL)
        {
            preSum=preSum+head->val;
            if(mp.find(preSum)!=mp.end())
            {
                ListNode* as=mp[preSum];
                ListNode* ass=as;
                int pSum=preSum;
                while(as!=head)
                {
                    as=as->next;
                    pSum=pSum+as->val;
                    if(as!=head)
                        mp.erase(pSum);
                }
                ass->next=head->next;
                
            }
            else{
                mp[preSum]=head;
            }
            head=head->next;
        }
        return dummy->next;
    }
};