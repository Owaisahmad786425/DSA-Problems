class Solution {
int fun(int index,bool buy,vector<int> &prices,int n,vector<vector<int>> &dp){
    if(index>=n){
        return 0;
    }
    if(dp[index][buy]!=-1){
        return dp[index][buy];
    }
int profit;
if(buy){
profit=max((-prices[index]+fun(index+1,0,prices,n,dp)),fun(index+1,1,prices,n,dp));
}
else{
    profit=max((+prices[index]+fun(index+2,1,prices,n,dp)),fun(index+1,0,prices,n,dp));
}
return dp[index][buy]=profit;

}

public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        bool buy=1;
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return fun(0,buy,prices,n,dp);
        
            }
};