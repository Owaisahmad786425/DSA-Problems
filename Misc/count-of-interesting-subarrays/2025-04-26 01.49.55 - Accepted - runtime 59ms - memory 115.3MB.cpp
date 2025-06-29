class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int m, int k) {
    unordered_map<int,int> mp;
    int n=nums.size();
    for(int i=0;i<n;i++){
        if(nums[i]%m==k){
            nums[i]=1;
        }
        else{
            nums[i]=0;
        }
    }    
    mp[0]++;
    long long res=0;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=nums[i];
        int r1=sum%m;
        int r2=(r1-k+m)%m;
        if(mp.find(r2)!=mp.end()){
            res+=mp[r2];
          
        }
          mp[r1]++;
    }

return res;
    }
};