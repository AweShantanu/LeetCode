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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode* > q;
        q.push(root);
        
        vector<vector<int>> res;
        if(!root)
            return res;
        while(!q.empty())
        {
            int n=q.size();
            vector<int> r;
            for(int i=0;i<n;i++)
            {
                TreeNode* data=q.front();
                q.pop();
                r.push_back(data->val);
                if(data->left)
                    q.push(data->left);
                if(data->right)
                    q.push(data->right);
                
            }
            res.push_back(r);
            
        
        }
        return res;
    }
};