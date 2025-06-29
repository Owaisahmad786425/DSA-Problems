class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int l=0;
        int r=0;
        int maxi=-1e9;
        int p=1;
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
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