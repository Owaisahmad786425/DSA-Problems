class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        vector<int> count(n,1);
        for(int curr=0;curr<n;curr++){
        for(int prev=0;prev<curr;prev++){
        if(nums[curr]>nums[prev] &&dp[prev]+1>dp[curr]){
            dp[curr]=1+dp[prev];
            count[curr]=count[prev];
        }
        else if(nums[curr]>nums[prev] && dp[prev]+1==dp[curr]){
            count[curr]+=count[prev];
        }
       }
        }
        int maxi=1;
       for(int i=0;i<count.size();i++){
            maxi=max(dp[i],maxi);
       }
       int res=0;
       for(int i=0;i<dp.size();i++){
        if(dp[i]==maxi){
            res+=count[i];
        }
       }
return res;
            }
};