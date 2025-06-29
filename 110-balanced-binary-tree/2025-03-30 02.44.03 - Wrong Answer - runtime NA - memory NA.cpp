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
    int fun(TreeNode* node){
        if(node==NULL){
            return 0;
        }
        int left=1+fun(node->left);
        int right=1+fun(node->right);
        return max(left,right);
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }
       int l= fun(root->left);
        int r=fun(root->right);
        if(abs(l-r)>1){
            return false;
        }
        return true;
    }
};