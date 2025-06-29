class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        for(int i=0;i<n;i++){
            dp[n-1][i]=matrix[n-1][i];
        }
        for(int i=n-2;i>=0;i--){
for(int j=0;j<n;j++){
    int left=INT_MAX;
    int down=INT_MAX;
    int right=INT_MAX;
    if(j-1>=0){
        left=matrix[i][j]+dp[i+1][j-1];
    }
    down=matrix[i][j]+dp[i+1][j];
    if(j+1<n){
        right=matrix[i][j]+dp[i+1][j+1];
    }
    dp[i][j]=min(min(left,right),down);
    }
        }
int mini=INT_MAX;
for(int i=0;i<n;i++){
    mini=min(mini,dp[0][i]);
}
        
        return mini;
    }
};