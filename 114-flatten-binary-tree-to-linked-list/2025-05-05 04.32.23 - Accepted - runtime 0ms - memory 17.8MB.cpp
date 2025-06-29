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
    void dfs(TreeNode* node,vector<TreeNode*>&pre_order){
        if(node==NULL){
            return;
        }
        pre_order.push_back(node);
        dfs(node->left,pre_order);
        dfs(node->right,pre_order);
    }
    
public:
    void flatten(TreeNode* root) {
        vector<TreeNode*> pre_order;
        dfs(root,pre_order);
          TreeNode* temp=root;
         for(int i=1;i<pre_order.size();i++){
           temp->left=NULL;
           temp->right=pre_order[i];
          temp=temp->right;
         }


    }
};