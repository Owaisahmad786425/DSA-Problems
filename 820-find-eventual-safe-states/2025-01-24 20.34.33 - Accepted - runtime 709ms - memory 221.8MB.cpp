class Solution {
void dfs(int node,vector<bool>&path,vector<bool> &vis,vector<vector<int>> &graph){
vis[node]=1;
path[node]=1;
for(auto it:graph[node]){
if(!vis[it]){
dfs(it,path,vis,graph);
}
if(path[it]){
    return;
}
}
path[node]=0;
}

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
vector<int> res;
      vector<bool> vis(n,0);
 vector<bool> path(n,0);
        for(int i=0;i<n;i++){
          
            vector<bool> vis(n,0);
            if(!vis[i]){
            dfs(i,path,vis,graph);
            }
        if(!path[i]){
            res.push_back(i);
        }

        }
        return res;
    }
};