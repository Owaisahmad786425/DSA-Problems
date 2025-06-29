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
        TreeNode* fun(int start,int end,int &pre_end,vector<int> &postorder,vector<int> &inorder,unordered_map<int,int> &mp,int n){
   //base case 
   if(pre_end<0 || start>end){
    return NULL;
   }
   int index=mp[postorder[pre_end]];
   TreeNode* node=new TreeNode(postorder[pre_end]);
    int rem_right=end-index;
   if(rem_right>0){
    pre_end--;
   node->right=fun(index+1,end,pre_end,postorder, inorder,mp,n);
   }
   else{
    node->right=NULL;
   }
   int rem_left=index-start;
   if(rem_left>0){
    pre_end--;
   node->left=fun(start,index-1,pre_end,postorder,inorder,mp,n);
   }else{
    node->left=NULL;
   }
  
   return node;

    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mp;
           int n=inorder.size();
           int start=0;
           int end=n-1;
           int pre_end=n-1;
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
    return fun(start,end,pre_end,postorder,inorder,mp,n);

 
    }
};