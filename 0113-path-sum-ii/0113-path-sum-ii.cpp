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
    
    void solve(TreeNode* root, int targetSum,int sum, vector<int> path,vector<vector<int>> &ans)
    {
        if(root==NULL)
        {
            return ;
            
        }
        if(root->left==NULL && root->right==NULL)
        {
            path.push_back(root->val);
            sum=sum+root->val;
            if(sum==targetSum)
            {
                ans.push_back(path);
                return;
            }
        }
        path.push_back(root->val);
        sum=sum+root->val;
        
        solve(root->left,targetSum,sum,path,ans);
        solve(root->right,targetSum,sum,path,ans);
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        int sum=0;
        vector<int> path;
        solve(root, targetSum,sum,path,ans);
        return ans;
    }
};