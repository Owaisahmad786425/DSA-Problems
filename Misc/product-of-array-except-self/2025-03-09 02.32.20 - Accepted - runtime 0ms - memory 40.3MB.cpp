class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prefix=1;
        int n=nums.size();
        //this we take for the prefix lets try wihtout extra space owais
        vector<int> ans(n);
   ans[n-1]=nums[n-1];
   for(int i=n-2;i>=0;i--){
    //now suffix is calculated
    ans[i]=ans[i+1]*nums[i];
   }
for(int i=0;i<n;i++){
    if(i==0){
        ans[i]=ans[i+1];
        prefix*=nums[i];
    }
    else if(i==n-1){
     ans[i]=prefix;
    }
    else{
        ans[i]=prefix*ans[i+1];
        prefix*=nums[i];
    }
 

}

return ans;

    }
};