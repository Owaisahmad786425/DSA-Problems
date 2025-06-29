class Solution {
    void dfs(int node,char &min_char,vector<vector<char>> &adj,vector<bool> &vis){
        vis[node]=1;
       if(min_char>(node+'a')){
        min_char=node+'a';
       }
        for(auto it:adj[node]){
            if(!vis[it-'a']){
              dfs(it-'a',min_char,adj,vis);
            }
        }
    }
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n=s1.size();
        int m=baseStr.size();
        vector<vector<char>> adj(26);
        //creation of adjacency list
        for(int i=0;i<n;i++){
            int a=s1[i];
            int b=s2[i];
            adj[a-'a'].push_back(b);
            adj[b-'a'].push_back(a);
        }
        string res;
        for(int i=0;i<m;i++){
            char min_char=baseStr[i];
            vector<bool> vis(26);
            dfs(baseStr[i]-'a',min_char,adj,vis);
            baseStr[i]=min_char;
        }
  return baseStr;
    }
};