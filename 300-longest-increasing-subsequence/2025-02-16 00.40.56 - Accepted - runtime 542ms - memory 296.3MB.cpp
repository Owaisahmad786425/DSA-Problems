class Solution {
 int fun(int index, int prev_index, vector<int> &nums,int n,vector<vector<int>> &dp){
//base case
if(index>=n){
    return 0;
}
if(dp[index][prev_index+1]!=-1){
    return dp[index][prev_index+1];
}
int take=-1e9;
int not_take=fun(index+1,prev_index,nums,n,dp);
if(prev_index==-1 || nums[index]>nums[prev_index]){
take=1+fun(index+1,index,nums,n,dp);
}
return dp[index][prev_index+1]=max(take,not_take);
 }



public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
   return fun(0,-1,nums,n,dp);
    }
};