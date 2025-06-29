class Solution {
    bool fun(int index,int total,int rem,int n, vector<int>&nums){
        if(index==n){
            if(total==rem){
                return true;
            }
            return false;
        }
        if(total==rem){
            return true;
        }
        bool take=fun(index+1,total-nums[index],rem+nums[index],n,nums);
        bool not_take=fun(index+1,total,rem,n,nums);
        return take|| not_take;
    }
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int total=0;
        int rem=0;
        for(int i=0;i<n;i++){
            total+=nums[i];
        }
        return fun(0,total,rem,n,nums);
    }
};