class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int i=0;
        int j=1;
        int k=2;
        long long  maxi=-1e9,mini=1e9,maxik=-1e9,result=0;
        int n=nums.size();
        while(k<n){
if(maxi<nums[i]){
    maxi=nums[i];
}
      if(mini>nums[j]){
        mini=nums[j];
      }
      if(maxik<nums[k]){
        maxik=nums[k];
      }
        long long maxdiff=maxi-mini;
        long long val=maxdiff*maxik;
        if(result<val){
            result=val;
        }
        i++;
        j++;
        k++;
        }
        return result;
    }
};