/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int right) {
        if(root==NULL)
            return 0;
        int ans=0;
        bool wasInRange=false;
        if(root->val>=low && root->val<= right)
        {
            ans=ans+root->val;
            wasInRange=true;
            
        }
        if(wasInRange)
        {
            ans+=rangeSumBST(root->left,low,right)+rangeSumBST(root->right,low,right);
        }
        else if(root->val<low)
        {
            ans=ans+rangeSumBST(root->right,low,right);
            
        }
        else{
            ans+=rangeSumBST(root->left,low,right);
            
        }
        return ans;
        
    }
};