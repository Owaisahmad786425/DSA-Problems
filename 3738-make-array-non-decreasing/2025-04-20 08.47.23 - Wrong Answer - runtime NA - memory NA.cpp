class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
      vector<int> ans;
        int n=nums.size();
        vector<int> temp;
        temp=nums;
        sort(temp.begin(),temp.end());
        if(temp==nums){
            return n;
        }
        int i=1;
        int prev=nums[0];
        while(i<n){
            if(i==n-1 && prev<nums[i]){
                ans.push_back(nums[i]);
                break;
            }
            if(prev>nums[i]){
                ans.push_back(prev);
                prev=nums[i];
                i++;
            }
            else{
                prev=nums[i];
                i++;
            }
        }
        return ans.size();
    }
};