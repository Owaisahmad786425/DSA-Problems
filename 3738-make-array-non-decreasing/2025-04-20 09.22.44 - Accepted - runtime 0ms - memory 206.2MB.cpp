class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int prev=nums[0];
       int count=1;
        

        int n=nums.size();
        if(n==1){
            return 1;
        }
       int i=1;
        while(i<n){
            if(nums[i]>=prev){
               count++;
                prev=nums[i];
            }
            i++;
        }

           
        
        return count;
    }
};