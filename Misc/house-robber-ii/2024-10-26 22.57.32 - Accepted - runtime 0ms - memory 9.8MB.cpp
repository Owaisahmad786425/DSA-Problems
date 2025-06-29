class Solution {
private:
int f1(int index,vector<int> &nums,vector<int> &dp){
    if(index==1){
        return nums[index];
    }
    if(index<1){
        return 0;
    }
    if(dp[index]!=-1)return dp[index];
int pick=nums[index]+f1(index-2,nums,dp);

int notpick=0+f1(index-1,nums,dp);
return dp[index]=max(pick,notpick);

}
int f2(int index,vector<int> &nums,vector<int> &dp1){
    if(index==0){
        return nums[index];
    }
    if(index<0){
        return 0;
    }
if(dp1[index]!=-1)return dp1[index];
    int pick=nums[index]+f2(index-2,nums,dp1);
    int notpick=0+f2(index-1,nums,dp1);
    return dp1[index]=max(pick,notpick);
}

public:
    int rob(vector<int>& nums) {
      int n=nums.size();
      vector<int> dp(n,-1);
       vector<int> dp1(n,-1);
      if(nums.size()==1){
        return nums[0];
      }
      int firstleft=f1(n-1,nums,dp);

      int secondleft=f2(n-2,nums,dp1); 
      return max(firstleft,secondleft);
    }
};