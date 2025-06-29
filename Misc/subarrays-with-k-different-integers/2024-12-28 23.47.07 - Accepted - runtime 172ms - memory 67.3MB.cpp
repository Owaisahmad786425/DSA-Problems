class Solution {
    int fun(vector<int> &nums,int temp){
        int l=0;
        int r=0;
        int n=nums.size();
        int count=0;
        map<int,int> mp;
        while(r<n){
            mp[nums[r]]++;
            while(mp.size()>temp){
                mp[nums[l]]--;
                if(mp[nums[l]]==0){
                    mp.erase(nums[l]);
                }
                l++;
            }
            if(mp.size()<=temp){
  count+=r-l+1;
            }
            r++;
        }
        return count;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return fun(nums,k)-fun(nums,k-1);
    }
};