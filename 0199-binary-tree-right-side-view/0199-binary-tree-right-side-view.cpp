/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr, right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr) return {};
        
        queue<TreeNode*> q;
        vector<int> res;
        q.push(root);
        
        while(!q.empty()) {
            int n = q.size();
            TreeNode* node = nullptr;
            
            for(int i = 0; i < n; ++i) {
                node = q.front();
                q.pop();
                
                if(node->left != nullptr) {
                    q.push(node->left);
                }
                
                if(node->right != nullptr) {
                    q.push(node->right);
                }
            }
            
            // Push the last node's value of the current level to the result
            if(node != nullptr) {
                res.push_back(node->val);
            }
        }
        
        return res;
    }
};
