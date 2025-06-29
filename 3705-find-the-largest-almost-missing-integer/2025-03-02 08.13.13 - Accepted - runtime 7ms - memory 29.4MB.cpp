class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
   int n=nums.size();
        unordered_map<int,int> mp;
        int l=0;
        int r=k-1;
        if(k==n){
 int ma=-1;
            for(int i=0;i<n;i++){
                ma=max(ma,nums[i]);
            }
            return ma;
            
        }
        while(r<n){

     for(int i=l;i<=r;i++){
         mp[nums[i]]++;
     }

            l++;
            r++;
        }
        int maxi=-1;
      
for(auto it:mp){
if(it.second==1){
    maxi=max(maxi,it.first);
}
    
}
      return maxi;
        
    }
};