class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long res=0;
        int l=0;
        int n=nums.size();
        int r=0;
        int maxi=-1e9;
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
        }
        int cnt=0;
        while(r<n){
            if(nums[r]==maxi){
                cnt++;
            }
            while(cnt==k){
               res+=n-r;
               if(nums[l]==maxi)cnt--;
                l++;
            }
            r++;
           
        }
        return res;
    }
};