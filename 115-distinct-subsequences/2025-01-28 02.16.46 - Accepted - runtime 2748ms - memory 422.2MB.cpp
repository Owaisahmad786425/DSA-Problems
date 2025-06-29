class Solution {
    int fun(int index1,int index2,string s, string t,vector<vector<int>> &dp){
      if(index2==0){
        return 1;
      }
      if(index1==0){
        return 0;
      }
if(dp[index1][index2]!=-1){
    return dp[index1][index2];
}

        if(s[index1-1]==t[index2-1]){
            return dp[index1][index2]=fun(index1-1,index2-1,s,t,dp)+fun(index1-1,index2,s,t,dp);
        }
        else{
  return dp[index1][index2]=fun(index1-1,index2,s,t,dp);
        }


      
    }
public:
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return fun(n,m,s,t,dp);
    }
};