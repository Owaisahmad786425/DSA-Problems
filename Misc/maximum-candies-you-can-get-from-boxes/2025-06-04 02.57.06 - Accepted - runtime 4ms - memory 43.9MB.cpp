class Solution {
    int dfs(int box,vector<bool>&vis,set<int> &store,vector<int> &status,vector<int>&candies,vector<vector<int>> &containedBoxes,vector<vector<int>> &keys){
        if(vis[box]){
            return 0;
        }
        if(status[box]==0){
            store.insert(box);
            return 0;
        }
        vis[box]=true;
           int candy=candies[box];
        for(auto neighbours:containedBoxes[box]){
            candy+=dfs(neighbours,vis,store,status,candies,containedBoxes,keys);
        }

        for(auto key:keys[box]){
          status[key]=1;
          if(store.find(key)!=store.end()){
            candy+=dfs(key,vis,store,status,candies,containedBoxes,keys);
          }
        }
        return candy;
    }
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n=status.size();
        int res=0;
        vector<bool> vis(n,0);
        set<int> store;
      for(int i=0;i<initialBoxes.size();i++){
        res+=dfs(initialBoxes[i],vis,store,status,candies,containedBoxes,keys);
      }
      return res;
    }
};