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
TreeNode* fun(int prestart,int poststart,int pre_end,vector<int>&preorder, vector<int>& postorder){
if(prestart>pre_end){
    return NULL;
}

TreeNode* root=new TreeNode(preorder[prestart]);
 if (prestart == pre_end) return root;
int j=poststart;
int num=preorder[prestart+1];
while(postorder[j]!=num){
    j++;
}
int size=j-poststart+1;

root->left=fun(prestart+1,poststart,prestart+size,preorder,postorder);
root->right=fun(prestart+size+1,j+1,pre_end,preorder,postorder);
return root;

}



public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
           int n=preorder.size();

           return fun(0,0,n-1,preorder,postorder);



    }
};