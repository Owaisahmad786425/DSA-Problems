class Solution {
public:
    int minOperations(vector<int>& nums) {
       int l=0;
       int r=l+2;
       int op=0;
       int n=nums.size();
       while(r<n){
        if(nums[l]==0){
            op++;
            for(int i=l;i<=r;i++){
                if(nums[i]==0){
          nums[i]=1;
                }
                else{
                    nums[i]=0;
                }
            }
        }
       l++;
       r++;
       } 
       while(l<n){
        if(nums[l]==0){
            break;
        }
        l++;
       }
       if(l<n){
        return -1;
       }
       return op;
    }
};