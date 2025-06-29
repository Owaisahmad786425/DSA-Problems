class Solution {
    void dfs1(int node,vector<vector<int>> &adj1,int target,int &cnt,vector<bool> &vis){
       vis[node]=1;
       if(target%2==0){
        cnt++;
       }
       for(auto it:adj1[node]){
        if(!vis[it]){
            dfs1(it,adj1,target+1,cnt,vis);
        }
       }
    }
        void dfs2(int node,vector<vector<int>> &adj2,int target,int &cnt,vector<bool> &vis){
       vis[node]=1;
       if(target%2!=0){
        cnt++;
       }
       for(auto it:adj2[node]){
        if(!vis[it]){
            dfs2(it,adj2,target+1,cnt,vis);
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
     dfs1(i,adj1,0,cnt,vis);
     answer[i]+=cnt;
   }
int maxi=-1e9;
   for(int i=0;i<m+1;i++){
 vector<bool> vis(n+1,0);
     int cnt=0;
     dfs2(i,adj2,0,cnt,vis);
    maxi=max(maxi,cnt);
   }
for(int i=0;i<n+1;i++){
answer[i]+=maxi;

}
return answer;

    }
};