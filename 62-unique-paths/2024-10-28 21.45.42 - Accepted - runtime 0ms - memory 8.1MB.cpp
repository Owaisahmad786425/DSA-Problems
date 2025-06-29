class Solution {
    private:
int f(int index1,int index2,int m,int n,vector<vector<int>> &dp){
   if(index1>m-1 || index2>n-1){
    return 0;
       }
       if(index1==m-1 &&index2==n-1){
    
        return 1;
       }
       if(dp[index1][index2]!=-1){
        return dp[index1][index2];
       }
       int right=f(index1,index2+1,m,n,dp);
       int down=f(index1+1,index2,m,n,dp);
       return  dp[index1][index2]=right+down;


  }

public:
    int uniquePaths(int m, int n) {
vector<vector<int>> dp(m,vector<int>(n,-1));
return f(0,0,m,n,dp);


    }
};