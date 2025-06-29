class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
      int total=0;
        int n =nums.size();
        for(int i=0;i<n;i++){
            total+=nums[i];
        }
        int res=(total%k);
        return res;
    }
};