class Solution {
    void dfs(int node,vector<vector<int>> &adj,vector<bool> &vis,vector<int> &label,int &zero_count,int &one_count,bool l){
        vis[node]=1;
        label[node]=l;
        if(l==0){
            zero_count++;
           
        }
        else{
            one_count++;
        }
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis,label,zero_count,one_count,!l);
            }
        }
    }
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
      int n=edges1.size();
      int m=edges2.size(); 

      vector<vector<int>>adj1(n+1);
      vector<vector<int>>adj2(m+1);
      //conversion
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
  int zero_count=0;
  int one_count=0;
  vector<bool> vis(n+1,0);
  vector<int> answer(n+1);
  vector<int> label(n+1);
  dfs(0,adj1,vis,label,zero_count,one_count,0);
for(int i=0;i<n+1;i++){
    if(label[i]==0){
        answer[i]+=zero_count;
        continue;
    }
    answer[i]+=one_count;
}
zero_count=0;
one_count=0;
vector<int> label2(m+1);
vector<bool> vis1(m+1,0);
dfs(0,adj2,vis1,label2,zero_count,one_count,1);
int maxi=max(zero_count,one_count);
for(int i=0;i<n+1;i++){
    answer[i]+=maxi;
}
return answer;
    }
};