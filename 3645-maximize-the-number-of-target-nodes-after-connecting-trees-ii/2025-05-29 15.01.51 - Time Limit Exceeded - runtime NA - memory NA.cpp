class Solution {
    void dfs(int node,vector<vector<int>> &adj,int target,int &cnt,vector<bool> &vis){
       vis[node]=1;
       if(target%2==0){
        cnt++;
       }
       for(auto it:adj[node]){
        if(!vis[it]){
            dfs(it,adj,target+1,cnt,vis);
        }
       }
    }
       
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n=edges1.size();
        int m=edges2.size();
        vector<vector<int>> adj1(n+1);
        vector<vector<int>> adj2(m+1);
     for(int i=0;i<n;i++){
        int a=edges1[i][0];
        int b=edges1[i][1];
         adj1[a].push_back(b);
        adj1[b].push_back(a);

     }
     for(int i=0;i<m;i++){
        int a=edges2[i][0];
        int b=edges2[i][1];
        adj2[a].push_back(b);
        adj2[b].push_back(a);
     }
     vector<int> answer(n+1);
    for(int i=0;i<n+1;i++){
     vector<bool> vis(n+1,0);
     int cnt=0;
     dfs(i,adj1,0,cnt,vis);
     answer[i]+=cnt;
   }
int maxi=-1e9;
   for(int i=0;i<m+1;i++){
 vector<bool> vis(m+1,0);
     int cnt=0;
     dfs(i,adj2,1,cnt,vis);
    maxi=max(maxi,cnt);
   }
for(int i=0;i<n+1;i++){
answer[i]+=maxi;

}
return answer;

    }
};