class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
   int n=nums.size();
   int max_sum=INT_MIN;
   int min_sum=INT_MAX;
int sum=0;
   for(int i=0;i<n;i++){
    sum+=nums[i];
    max_sum=max(max_sum,sum);
    if(sum<0){
        sum=0;
    }
   }
   sum=0;
for(int i=0;i<n;i++){
    sum+=nums[i];
    min_sum=min(min_sum,sum);
    if(sum>0){
        sum=0;
    }
}
  
return max(abs(max_sum),abs(min_sum));
    }
};