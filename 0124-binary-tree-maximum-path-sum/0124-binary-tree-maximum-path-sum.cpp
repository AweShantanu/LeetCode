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
    int maxi=INT_MIN;
    
    int solve(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int left=solve(root->left);
        int right=solve(root->right);
        
        int tino_mila_ke_achha_hai=left+right+root->val;
        int left_ya_right_achha_hai=max(left,right)+root->val;
        int sirf_root_achha_hai=root->val;
        maxi=max({maxi,tino_mila_ke_achha_hai,left_ya_right_achha_hai,sirf_root_achha_hai});
        return max(left_ya_right_achha_hai,sirf_root_achha_hai);
    }
    int maxPathSum(TreeNode* root) {
        solve(root);
        return maxi;
    }
};