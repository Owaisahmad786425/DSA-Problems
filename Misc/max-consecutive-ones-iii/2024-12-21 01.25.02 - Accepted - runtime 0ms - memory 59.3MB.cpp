class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int countz=0;
        int max_len=0;
        int l=0,r=0;
        int n=nums.size();
        while(r<n){
            if(nums[r]==0){
                countz++;
            }
            if(countz<=k){
                int len=(r-l)+1;
        max_len=max(max_len,len);
            }
            while(countz>k){
                if(nums[l]==0){
                    countz--;
                }
                l++;
            }
            r++;

        }
        return max_len;
    }
};