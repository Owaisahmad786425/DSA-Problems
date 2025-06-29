class Solution {
  vector<int> parent;
  int find(int x){
    if(parent[x]==x){
        return x;
    }
    return parent[x]=find(parent[x]);
  }
  void unionn(int x,int y){
    parent[y]=x;

  }

public:


    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        parent.resize(n+1);
        vector<int> cost(n+1);
  for(int i=0;i<parent.size();i++){
    parent[i]=i;
    cost[i]=-1;
  }
  for(auto egde:edges){
    int u=egde[0];
    int v=egde[1];
    int w=egde[2];
    int parent_u=find(u);
    int parent_v=find(v);
    if(parent_u!=parent_v){
        unionn(parent_u,parent_v);
        cost[parent_u]&=cost[parent_v];
    }
    cost[parent_u]&=w;
  }
  vector<int> res;
  for(auto &q:query){
    int s=q[0];
    int t=q[1];
    if(s==t){
        res.push_back(0);
    }
    int parent_s=find(s);
    int parent_s1=find(t);
    if(parent_s!=parent_s1){
        res.push_back(-1);
    }
    else{
        res.push_back(cost[parent_s]);
    }
  }
    return res;
    }
};