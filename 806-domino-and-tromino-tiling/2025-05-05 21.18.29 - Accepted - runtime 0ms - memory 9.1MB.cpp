class Solution {
    const int MOD=1000000007;
    int fun(int n,vector<int> &dp){
   if(n==1 ||n==0){
            return 1;
   }
        else if(n==2){
            return 2;
       }
       if(dp[n]!=-1){
        return dp[n];
       }
       return dp[n]=(2*fun(n-1,dp)%MOD+fun(n-3,dp)%MOD)%MOD;
    }
public:
    int numTilings(int n) {
     vector<int> dp(n+1,-1);
     return fun(n,dp);
    }
};