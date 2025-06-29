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
    int left_h(TreeNode* node){
        int count=0;
        while(node){
            count++;
            node=node->left;
        }
        return count;
    }

    int right_h(TreeNode* node){
        int count=0;
        while(node){
            count++;
            node=node->right;
        }
        return count;
    }
public:
    int countNodes(TreeNode* root) {
     if(root==NULL){
        return 0;
     }
     int lh=left_h(root);
     int rh=right_h(root);
     if(lh==rh){
        int temp= pow(2,lh)-1;
        return temp;
     }
     return 1+countNodes(root->left)+countNodes(root->right);
    }
};