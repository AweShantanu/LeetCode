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
    bool isBST(TreeNode* root,long long int lowerbound,long long int upperbound)
    {
        if(root==NULL)
        {
            return true;
        }        
        if(root->val>lowerbound && root->val<upperbound)
        {
            bool le=isBST(root->left,lowerbound,root->val);
            bool re=isBST(root->right,root->val,upperbound);
            return le && re;
        }
        else{
            return false;
        }
    }
    
    
    bool isValidBST(TreeNode* root) {
        long long int lowerbound=-393993993993;
        long long int upperbound=939939930202093;
        bool ans=isBST(root,lowerbound,upperbound);
        return ans;
    }
};