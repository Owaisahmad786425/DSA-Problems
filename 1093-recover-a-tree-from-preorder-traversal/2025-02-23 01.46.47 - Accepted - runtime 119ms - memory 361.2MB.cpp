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

    bool isdigit(char a){
 if(a=='1'||a=='2'|| a=='3'|| a=='4'|| a=='5'|| a=='6' || a=='7' || a=='8' || a=='9' || a=='0'){
    return true;
 }
 return false;


    }
TreeNode* fun(string s, int &i, int depth,int n){
if(i>=n){
    return NULL;
}
int j=i;
while(j<n && s[j]=='-'){
    j++;
}
int dash=j-i;
if(dash!=depth){
    return NULL;
}
int num=0;
i=j;
while(i<n && isdigit(s[i])){
    num=(num*10)+(s[i]-'0');
    i++;
}
TreeNode* node=new TreeNode(num);
node->left=fun(s,i,depth+1,n);
node->right=fun(s,i,depth+1,n);
return node;

}


public:
    TreeNode* recoverFromPreorder(string traversal) {
    int i=0;
    int n=traversal.size();
    return fun(traversal,i,0,n);


    }
};