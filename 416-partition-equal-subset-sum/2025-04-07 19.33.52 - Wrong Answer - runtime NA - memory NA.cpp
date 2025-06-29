class Solution {
public:
    bool canPartition(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int total=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            total+=nums[i];
        }
        int prefix=0;
        for(int i=0;i<n;i++){
            prefix+=nums[i];
            total-=nums[i];
            if(prefix==total){
                return true;
            }
        }
        return false;
    }
};