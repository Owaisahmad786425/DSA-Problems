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
unordered_map<int,int> mp;
int maxi=0;
TreeNode* lca(TreeNode* node){
    if(node==NULL || mp[node->val]==maxi){
        return node;
    }
    TreeNode* left=lca(node->left);
    TreeNode* right=lca(node->right);
    if(left && right){
return node;
    }
     return left!=NULL?left:right;
}
void depth(TreeNode* node,int d){
if(!node){
    return;
}
maxi=max(maxi,d);
mp[node->val]=d;
depth(node->left,d+1);
depth(node->right,d+1);
}
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        depth(root,0);
        return lca(root);
    }
};