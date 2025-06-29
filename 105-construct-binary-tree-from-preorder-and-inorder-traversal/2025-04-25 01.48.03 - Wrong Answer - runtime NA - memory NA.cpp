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
    TreeNode* fun(int start,int end,int pre_start,vector<int> &preorder,vector<int> &inorder,unordered_map<int,int> &mp,int n){
   //base case 
   if(pre_start>=n || start>end){
    return NULL;
   }
   int index=mp[preorder[pre_start]];
   TreeNode* node=new TreeNode(preorder[pre_start]);
   pre_start++;
   node->left=fun(start,index-1,pre_start,preorder,inorder,mp,n);
     pre_start++;
   node->right=fun(index+1,end,pre_start,preorder, inorder,mp,n);
   return node;
    }
   
 
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //base case 
         unordered_map<int,int> mp;
           int n=inorder.size();
           int start=0;
           int end=n-1;
           int pre_start=0;
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
    return fun(start,end,pre_start,preorder,inorder,mp,n);


    }
};