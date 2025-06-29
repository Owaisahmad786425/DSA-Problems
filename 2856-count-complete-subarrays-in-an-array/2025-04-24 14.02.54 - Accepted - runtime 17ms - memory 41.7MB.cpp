class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map<int,int> mp1,mp2;
        int n=nums.size();
        for(int i=0;i<n;i++){
           mp1[nums[i]]++;
        }
        int l=0;
        int r=0;
        int res=0;
        while(r<n){
            mp2[nums[r]]++;
            while(l<=r && mp1.size()==mp2.size()){
                res+=n-r;
                mp2[nums[l]]--;
                if(mp2[nums[l]]==0){
                    mp2.erase(nums[l]);
                }
                l++;
            }
            r++;
        }
        return res;
    }

};