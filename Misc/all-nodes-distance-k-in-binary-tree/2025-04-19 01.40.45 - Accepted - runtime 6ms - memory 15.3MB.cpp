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
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> mp;
        mp[root]=NULL;
        queue<TreeNode*> q;
        q.push(root);
        //plain bfs owais just to store the parent
        //parent concept is helpfull try to master it to
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