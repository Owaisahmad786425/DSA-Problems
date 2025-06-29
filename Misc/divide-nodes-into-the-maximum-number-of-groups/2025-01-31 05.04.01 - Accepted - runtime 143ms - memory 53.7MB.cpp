class Solution {
    void dfs(int node, vector<bool> &vis, vector<int> &color, vector<int> adj[],bool &flag){

        for(auto it:adj[node]){
            if(!vis[it] && color[it]!=color[node]){
                vis[it]=1;
                if(color[node]==1){
                    color[it]=2;
                }
                else{
                    color[it]=1;
                }
                dfs(it,vis,color,adj,flag);
            }
            if(vis[it] && color[it]==color[node]){
                flag=false;
            }
        }
    }

    void bfs(int node, vector<int> &levels, vector<int> adj[],int n){
vector<bool> visited(n+1,0);
  queue<int> q;
   q.push(node);
   visited[node]=1;
   int l=0;
   while(!q.empty()){
    int size=q.size();
    for(int i=0;i<size;i++){
        int temp=q.front();
        q.pop();
        for(auto it:adj[temp]){
            if(!visited[it]){
                visited[it]=1;
                q.push(it);
            }
        }
    }
    l++;
   }
levels[node]=l;
    }

    void dfs1(int node,vector<int> adj[], vector<bool> &visited,int &m1,vector<int> levels){
   visited[node]=1;
   m1=max(m1,levels[node]);
   for(auto it:adj[node]){
    if(!visited[it]){
        dfs1(it,adj,visited,m1,levels);
    }
   }
    }
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        //check weather it exist or not 
        vector<int> adj[n+1];
        for(int i=0;i<edges.size();i++){
        //construct the adjacency list
        adj[edges[i][0]].push_back(edges[i][1]);
           adj[edges[i][1]].push_back(edges[i][0]);
        }
vector<bool> vis(n+1);
vector<int> color(n+1,-1);

for(int i=1;i<=n;i++){
    bool flag=true;
    if(!vis[i]){
        color[i]=1;
        vis[i]=1;
       dfs(i,vis,color,adj,flag);
    }
    if(flag==false){
        return -1;
    }
}
vector<int> levels(n+1,0);

for(int i=1;i<=n;i++){
    bfs(i,levels,adj,n);
}
//we got the levels now time to have some trick
vector<bool> visited(n+1,0);
int maxi=0;
for(int i=1;i<=n;i++){
    int m1=0;
    if(!visited[i]){
        dfs1(i,adj,visited,m1,levels);
        maxi+=m1;
    }
}
return maxi;

    }
};