class Solution {
public:
    int countSubarrays(vector<int>& nums) {
       int n=nums.size();
       int l=0;
       int r=2;
      int res=0;
      while(r<n){
    if(nums[l]+nums[r]==nums[l+1]){
        res++;
    }
    l++;
    r++;
      }
      return res;
    }
};