class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
       bool state=0;
       int l=0;
       int r=0;
       int maxi=1;
       while(r<n-1){
        if(state==0){
            if(nums[r]>nums[r+1]){
                state=1;
                
                maxi=max(maxi,(r-l)+1);
                l=r;
            }
            else if(nums[r]<nums[r+1]){
                r++;
            }
            else if(nums[r]==nums[r+1]){
                   maxi=max(maxi,(r-l)+1);
             r++;
             l=r;
            }
        }
        else {
            if(nums[r]==nums[r+1]){
                   maxi=max(maxi,(r-l)+1);
                r++;
                l=r;
            }
            else if(nums[r]>nums[r+1]){
                r++;
            }
            else if(nums[r]<nums[r+1]){
               
                state=0;
                 maxi=max(maxi,(r-l)+1);
                  l=r;
            }
        }
       } 
       maxi=max(maxi,(r-l)+1);
       return maxi;
    }
};