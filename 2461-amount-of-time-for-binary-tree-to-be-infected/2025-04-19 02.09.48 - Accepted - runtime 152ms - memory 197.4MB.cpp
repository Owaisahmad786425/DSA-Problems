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
    TreeNode* locate(TreeNode* root,int start){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node->val==start){
                return node;
            }
    
            if(node->left!=NULL){
             q.push(node->left);
           }
          if(node->right!=NULL){
            q.push(node->right);
         }
        }
        return NULL;
    }
    void locate_parent(TreeNode* root, unordered_map<TreeNode*,TreeNode*> &mp){
        queue<TreeNode*> q;
       q.push(root);
       mp[root]=NULL;
       while(!q.empty()){
        TreeNode* node=q.front();
        q.pop();
        if(node->left!=NULL){
            mp[node->left]=node;
            q.push(node->left);
        }
        if(node->right!=NULL){
            mp[node->right]=node;
            q.push(node->right);
        }
       }
        }
public:
    int amountOfTime(TreeNode* root, int start) {
        // we have to find
        TreeNode* start_affection=locate(root,start);
        int res=0;
        unordered_map<TreeNode*,TreeNode*> mp;
             locate_parent(root,mp);
          queue<TreeNode*> q;
        q.push(start_affection);

   unordered_map<TreeNode*,int> vis;
   vis[start_affection]++;
   while(!q.empty()){
    int size=q.size();
    for(int i=0;i<size;i++){
        TreeNode* node=q.front();
        q.pop();
        if(mp[node]!=NULL && vis.find(mp[node])==vis.end()){
            vis[mp[node]]++;
            q.push(mp[node]);
        }
        if(node->left!=NULL && vis.find(node->left)==vis.end()){
            vis[node->left]++;
            q.push(node->left);
        }
        if(node->right!=NULL && vis.find(node->right)==vis.end()){
            vis[node->right]++;
            q.push(node->right);
        }
    }
    res++;
   }
   return res-1;
       }
};