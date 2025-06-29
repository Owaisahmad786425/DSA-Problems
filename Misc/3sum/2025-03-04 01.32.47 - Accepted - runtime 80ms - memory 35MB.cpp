class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> vec;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<=n-3;i++){
            if(i>0 && nums[i]==nums[i-1]){
               continue;
            }
            int j=i+1;
            int k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum<0){
                    j++;
                    while(j<n&& nums[j]==nums[j-1]){
                        j++;
                    }
                }
                else if(sum==0){
                    vector<int> temp;
                    temp.push_back(nums[i]);
                   temp.push_back(nums[j]);
                   temp.push_back(nums[k]);
                   vec.push_back(temp);
                   j++;
                   while(j<n &&nums[j]==nums[j-1] ){
                    j++;
                   }
                }
                else {
                    k--;
                    while(k>=0 && nums[k]==nums[k+1]){
                        k--;
                    }
                }
            }
        }
        return vec;
    }
};