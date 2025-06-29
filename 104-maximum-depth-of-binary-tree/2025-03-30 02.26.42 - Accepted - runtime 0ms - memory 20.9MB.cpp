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
    int maxDepth(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
     vector<vector<TreeNode*>> vec;
     if(root==NULL){
        return 0;
     }
     
        while(!q.empty()){
      vector<TreeNode*> temp;
      int s=q.size();
      for(int i=0;i<s;i++){
    TreeNode* node=q.front();
    q.pop();
    temp.push_back(node);
    if(node->left!=NULL){
        q.push(node->left);
    }
    if(node->right!=NULL){
        q.push(node->right);
    }
      }
      vec.push_back(temp);
        }
       return vec.size();
        
    }
};