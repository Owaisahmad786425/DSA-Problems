class Solution {
  int fun(int index,int target,vector<int> &coins,vector<vector<int>>&dp){
if(index==0){
    if(target%coins[index]==0){
        return target/coins[index];
    }
    else{
        return 1e9;
    }
}
if(dp[index][target]!=-1){
    return dp[index][target];
}
int not_take=0+fun(index-1,target,coins,dp);
int take=INT_MAX;
if(target>=coins[index]){
take=1+fun(index,target-coins[index],coins,dp);
}
return dp[index][target]=min(take,not_take);
  }
public:
    int coinChange(vector<int>& coins, int amount) {
   
   int n=coins.size();     
   vector<vector<int>> dp(n,vector<int>(amount+1,-1));

int mini=1e9;
mini= fun(n-1,amount,coins,dp);
if(mini==1e9){
    return -1;
}
return mini;
    }
};