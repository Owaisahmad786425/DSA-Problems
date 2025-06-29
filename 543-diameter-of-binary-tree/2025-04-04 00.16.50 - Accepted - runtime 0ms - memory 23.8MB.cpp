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

        int lh=1+fun(node->left,maxi);
        int rh=1+fun(node->right,maxi);
        maxi=max(maxi,(lh+rh));
        return max(lh,rh);

    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi=-1e9;
        int store=fun(root,maxi);
        return maxi-2;
    }
};