class Solution {
bool fun(int index,int target, int total,vector<int> &nums,vector<vector<int>> &dp){
if(index<0){
    return false;
}
if(total-target==target){
    return true;
}
if(dp[index][target]!=-1){
    return dp[index][target];
}
bool not_take=fun(index-1,target,total,nums,dp);
bool take=fun(index-1,target-nums[index],total,nums,dp);
return dp[index][target]=take || not_take;

}

public:
    bool canPartition(vector<int>& nums) {
        bool flag=0;
        int n=nums.size();
        int total=0;
        for(int i=0;i<n;i++){
total+=nums[i];
        }
        int target=total;
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return fun(n-1,target,total,nums,dp);
    }
};