class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
     int n=nums.size();
     int res=0;
     vector<bool> vis(n,0);
     for(int i=0;i<n;i++){
        if(vis[i]) continue;
        int maxi=-1e9;
        int mini=1e9;
        for(int j=i;j<n;j++){
            int store1=maxi;
            int store2=mini;
            maxi=max(maxi,nums[j]);
            mini=min(mini,nums[j]);
            if(maxi-mini>k){
                maxi=store1;
                mini=store2;
                continue;
            }
            vis[j]=1;
        }
        res++;
     }
     return res;   
    }
};