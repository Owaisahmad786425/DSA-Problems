class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
       long long res=0;
       int n=nums.size();
       int l=0;
       int r=0;
       int sum=0;
       while(r<n){
        sum+=nums[r];
        int len=r-l+1;
        if(len==1 && nums[r]<k){
            res++;
        }
        else if(nums[r]<k){
            res++;
        }
        int temp=sum*len;
        while(l<=r && temp>=k){
            sum-=nums[l];
            l++;
            if(l<=r){
                temp=(r-l+1)*sum;
            }
        }
        if(l<=r && (r-l+1)>1 &&temp<k){
            res++;
        }
        r++;
       } 
       return res;
    }
};