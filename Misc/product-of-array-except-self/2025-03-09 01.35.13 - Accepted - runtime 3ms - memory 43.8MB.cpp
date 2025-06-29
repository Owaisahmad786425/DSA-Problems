class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefix(n);
        vector<int> suffix(n);
        prefix[0]=nums[0];
        suffix[n-1]=nums[n-1];
        int i=1;
        int j=n-2;
        while(i<n && j>=0){
   prefix[i]=prefix[i-1]*nums[i];
   suffix[j]=suffix[j+1]*nums[j];
i++;
j--;
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(i==0){
                ans.push_back(suffix[i+1]);
            }
            else if(i==n-1){
                ans.push_back(prefix[i-1]);
            }
            else{
                ans.push_back(prefix[i-1]*suffix[i+1]);
            }
        }
return ans;
    }
};