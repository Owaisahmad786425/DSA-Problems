class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int> zeros(n,0);
        for(int i=0;i<queries.size();i++){
           zeros[queries[i][0]]-=1;
           if(queries[i][1]+1<n){
            zeros[queries[i][1]+1]+=1;
           }
        }
        for(int i=1;i<n;i++){
            zeros[i]=zeros[i-1]+zeros[i];
        }
        for(int i=0;i<n;i++){
            if(nums[i]==0) continue;
            nums[i]+=zeros[i];
            if(nums[i]>0){
                return false;
            }
        }
        return true;

    }
};