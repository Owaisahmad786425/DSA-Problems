class Solution {
//  int fun(int index, int prev_index, vector<int> &nums,int n,vector<vector<int>> &dp){
// //base case
// if(index>=n){
//     return 0;
// }
// if(dp[index][prev_index+1]!=-1){
//     return dp[index][prev_index+1];
// }
// int take=-1e9;
// int not_take=fun(index+1,prev_index,nums,n,dp);
// if(prev_index==-1 || nums[index]>nums[prev_index]){
// take=1+fun(index+1,index,nums,n,dp);
// }
// return dp[index][prev_index+1]=max(take,not_take);
//  }



public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));

     for(int i=n-1;i>=0;i--){
        for(int j=i-1;j>=-1;j--){
            int take=-1e9;
            int not_take=dp[i+1][j+1];
            if(j==-1 || nums[i]>nums[j]){
                take=1+dp[i+1][i+1];
            }
     dp[i][j+1]=max(take,not_take);
        }

     }

return dp[0][-1+1];
   
    }
};