class Solution {
    void fun(int index,vector<int> &hash,vector<int> &res,vector<int> &nums){
        if(index==hash[index]){
            res.push_back(nums[index]);
            return ;
        }

        res.push_back(nums[index]);
        fun(hash[index],hash,res,nums);
    }
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(n==1){
            return {nums[0]};
        }
        vector<int> dp(n,1);
        vector<int> hash(n);
        for(int i=0;i<n;i++){
            hash[i]=i;
        }
        int maxi=-1e9;
        int max_index;
        for(int curr=0;curr<n;curr++){
            for(int prev=0;prev<curr;prev++){
                if(nums[curr]%nums[prev]==0){
                    dp[curr]=max(dp[curr],(1+dp[prev]));
                    hash[curr]=prev;
                }
            }
            if(maxi<dp[curr]){
               maxi=max(maxi,dp[curr]);
               max_index=curr;
            }
        }
   vector<int> res;
   fun(max_index,hash,res,nums);
 reverse(res.begin(),res.end());
 return res;
    }
};