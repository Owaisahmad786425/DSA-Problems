class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
       int n=nums.size();
       vector<long long> prefixforward(n,0);
       vector<long long> prefixbackwards(n,0);
        //now for frontwards
        prefixforward[0]=nums[0];
        for(int i=1;i<n;i++){
            prefixforward[i]=prefixforward[i-1]+nums[i];
        }
//for backwards
prefixbackwards[n-1]=nums[n-1];
  for(int i=n-2;i>=0;i--){
            prefixbackwards[i]=prefixbackwards[i+1]+nums[i];
        }
int res=0;
for(int i=0;i<n-1;i++){
    if(prefixforward[i]>=prefixbackwards[i+1]){
        res++;
    }
}
return res;
    }
};