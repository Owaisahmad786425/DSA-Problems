class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
         int n=nums.size(),bitmask=0,l=0,r=0;
        int len=1;
        while(r<n){
            if((bitmask&nums[r])==0){
                bitmask|=nums[r];
                r++;
            len=max(len,(r-l));
            }
            else{
                bitmask^=nums[l];
                l++;
            }
 
            
        }
return len;

    }
};