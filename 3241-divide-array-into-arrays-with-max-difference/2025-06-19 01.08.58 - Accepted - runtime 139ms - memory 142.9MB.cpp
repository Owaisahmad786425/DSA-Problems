class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
     sort(nums.begin(),nums.end());
     int n=nums.size();
     int l=0;
     int r=2;
     vector<vector<int>> res;
     while(l<n &&r<n){
        for(int i=l;i<=r;i++){
         for(int j=i+1;j<=r;j++){
           if(abs(nums[i]-nums[j])>k){
            return {};
           }
         }

        }
        vector<int> temp;
        for(int i=l;i<=r;i++){
         temp.push_back(nums[i]);
        }
        res.push_back(temp);
        l+=3;
        r+=3;
     }

return res;
    }
};