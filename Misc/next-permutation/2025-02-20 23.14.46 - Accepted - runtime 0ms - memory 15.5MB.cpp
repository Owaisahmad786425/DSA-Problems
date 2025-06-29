class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int partition_index=-1;
        for(int i=n-1;i>0;i--){
            if(nums[i]>nums[i-1]){
                partition_index=i-1;
                break;
            }
        }
        if(partition_index==-1){
            sort(nums.begin(),nums.end());
            return;
        }
        int maxi=nums[partition_index+1];
        int max_index=partition_index+1;
        int r=max_index;
        while(r<n){
            if(nums[r]<maxi && nums[r]>nums[partition_index]){
                maxi=nums[r];
                max_index=r;
            }
            r++;
        }
   swap(nums[partition_index],nums[max_index]);
   sort(nums.begin()+partition_index+1,nums.end());


    }
};