class Solution {
    bool check(vector<int> &nums,int mid,int k){
        int count=0;
        for(int i=0;i<nums.size();i++){
    if(nums[i]<=mid){
        count++;
        i++;
    }
        }
        if(count>=k){
            return true;
        }
        return false;
    }
public:
    int minCapability(vector<int>& nums, int k) {
        int n=nums.size();
        int low=*min_element(nums.begin(),nums.end());
        int high=*max_element(nums.begin(),nums.end());
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(nums,mid,k)==true){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};