class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    int temp=dp[j]+1;
                    dp[i]=max(temp,dp[i]);
                }
            }
        }
        int maxi=1;
        for(int i=0;i<n;i++){
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
};