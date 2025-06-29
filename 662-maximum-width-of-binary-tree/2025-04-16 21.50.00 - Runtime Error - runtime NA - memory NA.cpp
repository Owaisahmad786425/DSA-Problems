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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int ans=0;
        while(!q.empty()){
            int mini=q.front().second;
            int first,last;
            int size=q.size();
            for(int i=0;i<size;i++){
                pair<TreeNode*,int> p;
                p=q.front();
            TreeNode* node=p.first;
            int curr_idx=p.second-mini;
            q.pop();
           if(i==0){
            first=curr_idx;
           }
           if(i==size-1){
            last=curr_idx;
           }
           if(node->left!=NULL){
          q.push({node->left,2*curr_idx+1});
           }
           if(node->right!=NULL){
            q.push({node->right,2*curr_idx+2});
           }
      
            }
            ans=max(ans,(last-first+1));
        }
return ans;
    }
};