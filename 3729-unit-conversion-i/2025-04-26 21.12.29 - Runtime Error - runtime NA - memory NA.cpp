class Solution {
    void dfs(int node,vector<vector<pair<int,int>>> &adj,vector<int>&res){
  
    for(auto it:adj[node]){
        
           
            res[it.first]=res[node]*it.second;
            dfs(it.first,adj,res);
        
    }

        
    }
public:
    vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
        int n=conversions.size();
        vector<vector<pair<int,int>>> adj(n+1);
        //convert it into adjacency list
        //keep in mind that this is an directed graph
        for(int i=0;i<n;i++){
            adj[conversions[i][0]].push_back({conversions[i][1],conversions[i][2]});
        }
     //now try dfs
       
        vector<int> res(n+1);
        res[0]=1;
        dfs(0,adj,res);
        return res;
    }
};