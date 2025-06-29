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
    void insertion_in_BST(TreeNode* node, int val){
        if(node->right==NULL &&node->val<val){
           TreeNode* temp=new TreeNode(val);
           node->right=temp;
            return;
        }
        if(node->left==NULL && node->val>val){
            TreeNode* temp=new TreeNode(val);
            node->left=temp;
            return;
        }
        if(node->val<val){
            insertion_in_BST(node->right,val);
        }
        else{
            insertion_in_BST(node->left,val);
        }
    }
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node1=new TreeNode(val);
        insertion_in_BST(root,val);
        return root;
    }
};