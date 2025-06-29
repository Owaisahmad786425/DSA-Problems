class Solution {
  /*int fun(int index,int target,vector<int> &coins,vector<vector<int>>&dp){
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
  }*/
public:
    int coinChange(vector<int>& coins, int amount) {
   
   int n=coins.size();     
   vector<vector<int>> dp(n,vector<int>(amount+1,-1));

//base case
for(int i=0;i<=amount;i++){
    if(i%coins[0]==0){
        dp[0][i]=i/coins[0];
    }
    else{
        dp[0][i]=INT_MAX;
    }
}
//base case done
//identify the loop
for(int i=1;i<n;i++){
    for(int j=0;j<=amount;j++){
        int not_take=0+dp[i-1][j];
        int take=1e9;
        if(j>=coins[i]){
            take=1+dp[i][j-coins[i]];
        }
        dp[i][j]=min(take,not_take);
    }
}
if(dp[n-1][amount]==INT_MAX || dp[n-1][amount]>=1e9){
    return -1;
} 
return dp[n-1][amount];
    }
};