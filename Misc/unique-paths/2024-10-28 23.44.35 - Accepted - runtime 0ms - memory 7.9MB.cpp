class Solution {
public:
    int uniquePaths(int m, int n) {
     vector<vector<int>> dp(m,vector<int>(n,-1));
     for(int i=m-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            if(i==m-1 &&j==n-1){
                dp[i][j]=1;
            }
            else{
                int up=0;
                if(i<m-1){
                    up=dp[i+1][j];
                }
                int left=0;
                if(j<n-1){
                    left=dp[i][j+1];
                }
                dp[i][j]=up+left;
            }
        }
     }
return dp[0][0];
    }
};