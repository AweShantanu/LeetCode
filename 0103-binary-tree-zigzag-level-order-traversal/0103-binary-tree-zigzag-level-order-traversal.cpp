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
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        bool dd=true;
        q.push(root);
        if(root==NULL)
        {
            return ans;
        }
        while(!q.empty())
        {
            int len=q.size();
            vector<int> arr(len);
            for(int i=0;i<len;i++)
            {
                TreeNode* temp=q.front();
                q.pop();
                int index=dd ? i:len-i-1;
                arr[index]=temp->val;
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
                
            }
            dd=!dd;
            ans.push_back(arr);
        }
        return ans;
        
        
    }
};