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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
      
        q.push(root);
        vector<vector<int>> vec;
          if(root==NULL){
            return vec;
        }
        int t=root->val;
        vec.push_back({t});
        int index=0;
        while(!q.empty()){
            vector<int> temp;
            for(int i=1;i<=vec[index].size();i++){
                TreeNode* te=q.front();
                q.pop();
                if(te->left!=NULL){
                    q.push(te->left);
                    temp.push_back(te->left->val);
                }
                  if(te->right!=NULL){
                    q.push(te->right);
                    temp.push_back(te->right->val);
                }
            }
            index++;
            if(temp.size()>0){
            vec.push_back(temp);
            }
        } 
return vec;
    }
};