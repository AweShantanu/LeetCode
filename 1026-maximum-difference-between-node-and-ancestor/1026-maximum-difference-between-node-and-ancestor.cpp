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
    int maxD(TreeNode* root,int maxi,int mini)
    {
        if(root==NULL)
            return abs(maxi-mini);
        
        mini=min(mini,root->val);
        maxi=max(maxi,root->val);
        
        int l=maxD(root->left,maxi,mini);
        int r=maxD(root->right,maxi,mini);
        
        return max(l,r);
    }
    int maxAncestorDiff(TreeNode* root) {
        return maxD(root,root->val,root->val);
    }
};