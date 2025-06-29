class Solution {
    const int M=1000000007;
public:
    int numTilings(int n) {
        vector<int> dp(n+1,-1);
        if(n==1 ||n==2){
            return n;
        }
        dp[0]=1;
        dp[1]=1;
        dp[2]=2;
    
        for(int i=3;i<=n;i++){
            dp[i]=(2*dp[i-1]%M + dp[i-3]%M)%M;
        }
        return dp[n];
    }
};