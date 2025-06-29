class Solution {
    void dfs(bool &flag,int node,vector<int> &vis,vector<vector<int>> &adj,int val){
        vis[node]=1;
        if(node==val){
            flag=true;
        }
        for(auto it:adj[node]){
            if(!vis[it] && flag==false){
                dfs(flag,it,vis,adj,val);
            }
        }
    }
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adj(numCourses); 
   int sizep=prerequisites.size();
   int sizeq=queries.size();
   //contruct the graph
   for(int i=0;i<sizep;i++){
    adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
   }     
   map<vector<int>, int> mp;
   for(int i=0;i<sizep;i++){
    mp[prerequisites[i]]++;
   }
vector<bool> res;
for(int i=0;i<sizeq;i++){
    if(mp.find(queries[i])!=mp.end()){
        res.push_back(true);
    }
    else{
        bool flag=false;
        int val=queries[i][1];
        vector<int> vis(numCourses,0);
        dfs(flag,queries[i][0],vis,adj,val);
        res.push_back(flag);
    }
}
return res;
    }
};