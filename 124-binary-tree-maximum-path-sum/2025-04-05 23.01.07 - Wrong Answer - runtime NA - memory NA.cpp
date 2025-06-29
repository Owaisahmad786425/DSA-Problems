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
    int fun(TreeNode* node,int &maxi){
        if(node==NULL){
            return 0;
        }
        int left=fun(node->left,maxi);
        int right=fun(node->right,maxi);
        maxi=max(maxi,(left+right+node->val));
        return max(left+node->val,right+node->val);
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxi=root->val;
        int store=fun(root,maxi);
        return maxi;
    }
};