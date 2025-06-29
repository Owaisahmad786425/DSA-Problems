 class Solution {

public:
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,0));
        //base case
  dp[0][0]=true;
    for (int i = 1; i <= m; i++) {
            if (p[i - 1] == '*') {
                dp[0][i] = dp[0][i - 1];  
            }
        }
  for(int j=1;j<=n;j++){
    dp[j][0]=false;
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
        if(s[i-1]==p[j-1] || p[j-1]=='?'){
            dp[i][j]=dp[i-1][j-1];
        }
        if(p[j-1]=='*'){
            dp[i][j]=(dp[i][j-1]||dp[i-1][j]);
        }
    }
  }


        return dp[n][m];
    }
};