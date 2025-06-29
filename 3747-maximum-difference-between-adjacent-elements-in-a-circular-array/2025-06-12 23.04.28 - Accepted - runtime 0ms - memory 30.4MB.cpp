class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n=nums.size();
        int res=-1e9;
     for(int i=0;i<n;i++){
        if(i==n-1){
            res=max(res,abs(nums[i]-nums[0]));
            continue;
        }
        res=max(res,abs(nums[i]-nums[i+1]));
     }
        return res;
    }
};