class Solution {
    int fun(vector<int> &nums, int x){
        int l=0,r=0;
        int n=nums.size();
        int count=0;
        int odd_count=0;
        while(r<n){
            if(nums[r]%2!=0){
                odd_count++;
            }
            while(odd_count>x){
                if(nums[l]%2!=0){
                    odd_count--;
                }
                l++;
            }
            if(odd_count<=x){
                count+=r-l+1;
            }
            r++;
        }
        return count;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return fun(nums,k)-fun(nums,k-1);
    }
};