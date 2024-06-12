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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int start, int end, int &index) {
        if (start > end) {
            return nullptr;
        }
        
        int ro = preorder[index++];
        TreeNode* root = new TreeNode(ro);
        
        int i = start;
        for (; i <= end; i++) {
            if (ro == inorder[i]) {
                break;
            }
        }
        
        root->left = solve(preorder, inorder, start, i - 1, index);
        root->right = solve(preorder, inorder, i + 1, end, index);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index = 0;
        return solve(preorder, inorder, 0, preorder.size() - 1, index);
    }
};
