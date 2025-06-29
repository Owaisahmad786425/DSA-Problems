class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
       int n=nums.size();
   long long leftsum=0;
   long long rightsum=0;
   for(int i=0;i<n;i++){
    rightsum+=nums[i];
   }
   int res=0;
 for(int i=0;i<n-1;i++){
    leftsum+=nums[i];
    rightsum-=nums[i];
    if(leftsum>=rightsum){
        res++;
    }
 }

return res;
    }
};