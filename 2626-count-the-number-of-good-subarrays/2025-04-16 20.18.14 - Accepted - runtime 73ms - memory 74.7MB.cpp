class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
   unordered_map<int,int> mp;
   int n=nums.size();
   int l=0, r=0;
   long long pair=0,res=0;
   while(r<n){
    mp[nums[r]]++;
    pair+=(mp[nums[r]]-1);
   while(pair>=k){
    res+=n-r;
    pair-=(mp[nums[l]]-1);
    mp[nums[l]]--;
    if(mp[nums[l]]==0){
        mp.erase(nums[l]);
    }
    l++;
   }
   r++;
   }
return res;
    }
};