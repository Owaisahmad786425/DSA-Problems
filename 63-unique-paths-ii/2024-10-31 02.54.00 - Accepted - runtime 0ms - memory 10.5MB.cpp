class Solution {
    int function(int index1,int index2,vector<vector<int>> &obstacleGrid, vector<vector<int>> &dp){
if(index1==0 &&index2==0){
    return 1;
}
if(index1<0 || index2<0 || obstacleGrid[index1][index2]==1){
    return 0;
}
if(dp[index1][index2]!=-1){
    return dp[index1][index2];
}
int left=function(index1,index2-1,obstacleGrid,dp);
int up=function(index1-1,index2,obstacleGrid,dp);
return dp[index1][index2]=left+up;



    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        if(obstacleGrid[0][0]==1 ||obstacleGrid[m-1][n-1]==1){
            return 0;
        }
        int res=function(m-1,n-1,obstacleGrid,dp);
        return res;
    }
};