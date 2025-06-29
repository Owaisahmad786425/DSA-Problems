class Solution {
public:
    int findNumbers(vector<int>& nums) {
       int n=nums.size();
       //new concept
       int cnt=0;
       for(int i=0;i<n;i++){
        int digcnt=(int)floor(log10(nums[i]))+1;
        if(digcnt%2==0){
            cnt++;
        }
       } 
       return cnt;
    }
};