class Solution {
    void dfs(int node,vector<bool>&vis,vector<bool> &pathvis ,vector<vector<int>> &graph,vector<bool> &check) {
pathvis[node]=1;
vis[node]=1;
for(auto it:graph[node]){
    if(!vis[it]){
        dfs(it,vis,pathvis,graph,check);
    }
    if(pathvis[it]){
        return;
    }
 
}

check[node]=1;
pathvis[node]=0;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<bool> vis(n,0);
        vector<bool> check(n,0);
        vector<bool> pathvis(n,0);
        for(int i=0;i<n;i++){
      if(!vis[i]){
        dfs(i,vis,pathvis,graph,check);
      }
        }
        vector<int> res;
        for(int i=0;i<n;i++){
            if(check[i]==1){
                res.push_back(i);
            }
        }
        return res;
    }
};