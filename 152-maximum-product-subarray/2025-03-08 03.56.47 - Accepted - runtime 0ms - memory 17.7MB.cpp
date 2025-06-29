class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int l=0,r=0,maxi=-1e9,p=1,n=nums.size();
        while(r<n){
      if(nums[r]==0){
         maxi=max(maxi,0);
         while(l<r){
      p/=nums[l];
      if(p!=1 ||(p==1 && l<r-1)){
    maxi=max(maxi,p);
      }
      l++;
         }
       r++;
       l=r;
      }
      else if(r==n-1){
        p*=nums[r];
        maxi=max(maxi,p);
        while(l<=r){
        p/=nums[l];
        if(p!=1 ||(p==1 &&l<n-1)){
           maxi=max(maxi,p);
        }
        l++;
        }
        break;
      }
      else{
p*=nums[r];
maxi=max(maxi,p);
r++;
      }
        }

return maxi;

    }
};