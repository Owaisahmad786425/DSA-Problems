class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
       sort(nums.begin(),nums.end());
       int n=nums.size();
       int low=0;
       int high=abs(nums[n-1]-nums[0]);
       int res=0;
       while(low<=high){
        int mid=(low+high)/2;
        int i=0;
        int count=0;
        while(i<n){
            if(i<n-1 && abs(nums[i]-nums[i+1])<=mid){
                count++;
                i+=2;
                continue;
            }
            i++;
        }
        if(count>=p){
            res=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
       }
       return res;
    }
};