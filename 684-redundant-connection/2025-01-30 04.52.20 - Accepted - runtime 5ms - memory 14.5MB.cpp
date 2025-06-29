class Solution {
bool dfs(int src, int target, vector<bool> &vis, vector<vector<int>> &adj){
vis[src]=1;
if(src==target){
    return true;
}
bool isthere=false;
for(auto it:adj[src]){
    if(!vis[it]){
 isthere=isthere|dfs(it,target,vis, adj);
    }
}
return isthere;
}

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
     int n=edges.size();
     vector<vector<int>> adj(n+1);

  for(int i=0;i<n;i++){
    int u=edges[i][0];
    int v=edges[i][1];
vector<bool> vis(n);
    if(dfs(u,v,vis,adj)){
        return edges[i];
    }
adj[u].push_back(v);
adj[v].push_back(u);

  }
return {};
    }
};