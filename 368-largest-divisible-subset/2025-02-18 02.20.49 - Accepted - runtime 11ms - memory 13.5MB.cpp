class Solution {
    void fun(int ind, vector<int> hash, vector<int> &nums,vector<int> &res){
        if(hash[ind]==ind){
            res.push_back(nums[ind]);
            return;
        }

        res.push_back(nums[ind]);
        fun(hash[ind],hash,nums,res);
    }
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
     int n=nums.size();
     sort(nums.begin(),nums.end());
     vector<int> dp(n,1);
     vector<int> hash(n);
 for(int i=0;i<n;i++){
    hash[i]=i;
 }
for(int i=0;i<n;i++){
 for(int j=0;j<i;j++){
    if(nums[i]%nums[j]==0 || nums[j]%nums[i]==0){
        if(1+dp[j]>dp[i]){
            dp[i]=1+dp[j];
            hash[i]=j;
        }
    }
 }
}
int index;
int maxi=0;
for(int i=0;i<n;i++){
   if(maxi<dp[i]){
    maxi=dp[i];
    index=i;
   }
}
vector<int> res;

fun(index,hash,nums,res);
reverse(res.begin(),res.end());
return res;

    }
};