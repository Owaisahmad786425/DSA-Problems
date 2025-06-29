class Solution {
//     bool fun(int index,vector<int> &nums,int target, vector<vector<int>> &dp){
//         if(index<0){
//             return false;
//         }
//         if(target==0){
//             return true;
//         }
//         if(dp[index][target]!=-1){
//             return dp[index][target];
//         }
// bool not_take=fun(index-1,nums,target,dp);
// bool take=false;
// if(target>=nums[index]){
//     take=fun(index-1,nums,target-nums[index],dp);
// }
// return dp[index][target]=take|| not_take;
//     }
public:
    bool canPartition(vector<int>& nums) {
        int total=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            total+=nums[i];
        }

        if(total%2!=0){
            return false;
        }
   
       int target=total/2;
         vector<vector<bool>> dp(n+1,vector<bool>(target+1,false));
         //base case
for(int i=0;i<n;i++){
    dp[i][0]=true;
}
for(int i=1;i<n;i++){
    for(int t=1;t<=target;t++){
        bool not_take=dp[i-1][t];
        bool take=false;
        if(t>=nums[i]){
       take=dp[i-1][t-nums[i]];
      
        }
         dp[i][t]=take||not_take;
    }
}

       return dp[n-1][target];
    }
};