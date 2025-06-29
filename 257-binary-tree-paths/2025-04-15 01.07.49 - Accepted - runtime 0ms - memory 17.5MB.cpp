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
    void dfs(TreeNode* node, vector<string> &res,string s){
      
        if(node->left==NULL && node->right==NULL){
           string value=to_string(node->val);
            s+=value;
            res.push_back(s);
            return;
        }
     
        if(node->left!=NULL){
               string value=to_string(node->val);
        s+=value;
         s.push_back('-');
        s.push_back('>');
        dfs(node->left,res,s);
        s.pop_back();
       s.pop_back();
         for(int i=0;i<value.size();i++){
            s.pop_back();
         }
        }
        if(node->right!=NULL){
               string value=to_string(node->val);
        s+=value;
        s.push_back('-');
        s.push_back('>');
        dfs(node->right,res,s);
        s.pop_back();
           s.pop_back();
                for(int i=0;i<value.size();i++){
            s.pop_back();
         }
        }
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        string s;
        dfs(root,res,s);
        return res;
    }
};