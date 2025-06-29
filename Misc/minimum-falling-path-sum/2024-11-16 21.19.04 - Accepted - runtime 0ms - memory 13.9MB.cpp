class Solution {
    int fun(int row,int col, vector<vector<int>> &matrix,int n,vector<vector<int>> &dp){
        if(row>=n || col>=n){
            return 0;
        }//logic ko dry run kro
        if(dp[row][col]!=INT_MAX){
            return dp[row][col];
        }
        int left=INT_MAX;
        int right=INT_MAX;
        int down=INT_MAX;

        if(col-1>=0){
            left=matrix[row][col]+fun(row+1,col-1,matrix,n,dp);
        }
        down=matrix[row][col]+fun(row+1,col,matrix,n,dp);
        if(col+1<n){
            right=matrix[row][col]+fun(row+1,col+1,matrix,n,dp);
        }
        return dp[row][col]=min(left,min(right,down));
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int mini=INT_MAX;
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        for(int i=0;i<n;i++){
            mini=min(mini,fun(0,i,matrix,n,dp));
        }
return  mini;
    }
};