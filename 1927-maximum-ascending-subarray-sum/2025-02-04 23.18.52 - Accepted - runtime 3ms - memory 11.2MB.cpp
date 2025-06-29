class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int r=0;
       int sum=0;
       int maxi=INT_MIN;
       
        while(r<n){
            if(r==n-1){
                sum+=nums[r];
                maxi=max(maxi,sum);
                r++;
            }
            else if(nums[r]<nums[r+1]){
                sum+=nums[r];
                r++;
            }
          else if(nums[r]>=nums[r+1]){
            sum+=nums[r];
            maxi=max(maxi,sum);
            sum=0;
            r++;
            l=r;
          }
        }
        return maxi;
    }
};