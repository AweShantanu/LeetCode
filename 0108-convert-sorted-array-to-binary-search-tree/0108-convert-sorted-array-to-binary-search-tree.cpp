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
    TreeNode* solve(vector<int>& nums,int start,int end)
    {
        if(start>end)
        {
            return NULL;
        }
    
        int mid=start+(end-start)/2;
        int element=nums[mid];
        TreeNode* mi=new TreeNode(element);
        mi->left=solve(nums,start,mid-1);
        mi->right=solve(nums,mid+1,end);
        return mi;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int start=0;
        int end=nums.size()-1;
        int mid;
        return solve(nums,start,end);
        
    }
};