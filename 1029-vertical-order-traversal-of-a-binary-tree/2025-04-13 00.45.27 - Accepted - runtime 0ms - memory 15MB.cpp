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
    void dfs(TreeNode* node,int row,int col, vector<pair<int,pair<int,int>>> &vec){
        if(node==NULL){
            return ;
        }
        vec.push_back({col,{row,node->val}});
        dfs(node->left,row+1,col-1,vec);
        dfs(node->right,row+1,col+1,vec);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
   vector<pair<int,pair<int,int>>> vec;
   dfs(root,0,0,vec);
sort(vec.begin(),vec.end());
int i=0;
vector<vector<int>> res;
int n=vec.size();
while(i<n){
    vector<int> temp;
    int num=vec[i].first;
    while(i<n && vec[i].first==num){
        temp.push_back(vec[i].second.second);
        i++;
    }
    res.push_back(temp);

}
return res;

    }
};