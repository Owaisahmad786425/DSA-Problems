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
        int left=max(0,fun(node->left,maxi));
        int right=max(0,fun(node->right,maxi));
     maxi=max(maxi,(left+right+node->val));
     return node->val+max(left,right);
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxi=-1e9;
        int store=fun(root,maxi);
        return maxi;
    }
};