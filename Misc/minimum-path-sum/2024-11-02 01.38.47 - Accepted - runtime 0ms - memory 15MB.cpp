class Solution {
private:
int fun(int index1,int index2,vector<vector<int>>&grid,vector<vector<int> >&dp){
    if(index1==0&&index2==0){
        return grid[index1][index2];
    }
    //noo need of taking this because its not a part of path
    if(index1<0 || index2<0){
       
        return INT_MAX;
    }
    if(dp[index1][index2]!=-1){
        return dp[index1][index2];
    }
  int up=fun(index1-1,index2,grid,dp);
  int left=fun(index1,index2-1,grid,dp);
    if(up!=INT_MAX)up+=grid[index1][index2];
      if(left!=INT_MAX)left+=grid[index1][index2];
    return  dp[index1][index2]=min(up,left);
}

public:
    int minPathSum(vector<vector<int>>& grid) {
     
        int m=grid.size();

        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));

        return fun(m-1,n-1,grid,dp);
   
    }
};