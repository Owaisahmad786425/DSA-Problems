class Solution {
//     int fun(int index1,int index2,string s,string s1,vector<vector<int>> &dp){
//         if(index1==0 || index2==0){
//             return 0;
//         }
// if(dp[index1][index2]!=-1){
//     return dp[index1][index2];
// }
// if(s[index1-1]==s1[index2-1]){
//     return dp[index1][index2]=1+fun(index1-1,index2-1,s,s1,dp);
// }
// return dp[index1][index2]=max(fun(index1-1,index2,s,s1,dp),fun(index1,index2-1,s,s1,dp));

//     }
public:
    int longestPalindromeSubseq(string s) {
      int n=s.size();
      string s1;
      //lets tabulate it
      for(int i=n-1;i>=0;i--){
        s1.push_back(s[i]);
      }
      vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
   for(int i=0,j=0;i<=n && j<=n;i++,j++){
    dp[i][0]=0;
   dp[0][j]=0;
   }
   for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
if(s[i-1]==s1[j-1]){
    dp[i][j]=1+dp[i-1][j-1];
}
else{
    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
}
    }
   }
return dp[n][n];
    }
};