class Solution {
    void dfs(int node, vector<int>&edges,vector<int> &store,int value,vector<bool>&vis){
         store[node]=value;
         vis[node]=1;
         if(edges[node]!=-1 && !vis[edges[node]])
         dfs(edges[node],edges,store,value+1,vis);
    }
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        vector<int> store1(n,-1);
        vector<bool> vis1(n,0);
        dfs(node1,edges,store1,0,vis1);
        vector<int> store2(n,-1);
        vector<bool> vis2(n,0);
        dfs(node2,edges,store2,0,vis2);
       vector<int> actual(n,-1);
      for(int i=0;i<n;i++){
        if(store1[i]!=-1 && store2[i]!=-1){
            actual[i]=max(store1[i],store2[i]);
        }
      }
      int index=-1;
      int mini=1e9;
      for(int i=0;i<n;i++){
     if(mini>actual[i] && actual[i]!=-1){
        index=i;
        mini=actual[i];
     }
      }
       return index;
    }
};