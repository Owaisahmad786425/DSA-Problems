/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void bfs_for_parent(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &mp){
        queue<TreeNode*> q1;
        q1.push(root);
     while(!q1.empty()){
          TreeNode* node=q1.front();
          q1.pop();
          if(node->left!=NULL){
            mp[node->left]=node;
            q1.push(node->left);
          }
          if(node->right!=NULL){
            mp[node->right]=node;
            q1.push(node->right);
          }
        }
        }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> mp;
        mp[root]=NULL;
      bfs_for_parent(root,mp);
        queue<TreeNode*> q;
   q.push(target);
   int distance=0;
   unordered_map<TreeNode*,int> vis;
   vis[target]++;
   while(distance<k){
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
      distance++;

   }
vector<int> res;
while(!q.empty()){
    res.push_back(q.front()->val);
    q.pop();
}
return res;
    }
};