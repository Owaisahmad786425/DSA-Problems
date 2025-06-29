class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int prev=nums[0];
       
        vector<int> ans;
        int n=nums.size();
        if(n==1){
            return 1;
        }
       int i=1;
        while(i<n){
            if(nums[i]>=prev){
                ans.push_back(prev);
                prev=nums[i];
            }
            i++;
        }
        if(prev>=ans[ans.size()-1]){
            ans.push_back(prev);
        }
        return ans.size();
    }
};