class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n=nums.size();
        int res=-1e9;
        for(int i=0;i<n;i++){
          if(i==0){
            res=max(res,abs(nums[i]-nums[i+1]));
          }
          else if(i==n-1){
            res=max(res,max(abs(nums[i]-nums[i-1]),abs(nums[i]-nums[0])));
          }
          else{
            res=max(res,max(abs(nums[i]-nums[i-1]),abs(nums[i]-nums[i+1])));
          }
        }
        return res;
    }
};