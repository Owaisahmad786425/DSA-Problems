class Solution {
    int fun(int index,int t,vector<int> nums,vector<vector<int>> &dp,int offset){
//base case
if(index<0){
    if(t==0){
        return 1;
    }
    else{
        return 0;
    }
}
//we have also to ensure that offset should bw within the bound and not exceed out of bound
   if (t + offset < 0 || t + offset >= dp[0].size()) {
            return 0; 
        }
if(dp[index][t+offset]!=-1){
    return dp[index][t+offset];
}
//+
int plus=fun(index-1,t-nums[index],nums,dp,offset);
//-
int minus=fun(index-1,t+nums[index],nums,dp,offset);
return dp[index][t+offset]=plus+minus;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;
        //negative value can also be encountered in target that we have to keep in mind dont 
        //we learn by mistakes only
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }

        vector<vector<int>> dp(n,vector<int>(2*sum+1,-1));
        int offset=sum;
        return fun(n-1,target,nums,dp,offset);
    }
};