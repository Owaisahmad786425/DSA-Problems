class Solution {
public:
    int subarraySum(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefix(n,0);
        prefix[0]=nums[0];
        //precompute
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
        //main logic 
        int sum=0;
        for(int i=0;i<n;i++){
            int start=max(0,i-nums[i]);
            if(start==0){
                sum+=prefix[i];
            }
            else{
                int temp=prefix[i];
                int temp2=prefix[start-1];
                sum+=temp-temp2;
            }
        }
return sum;
    }
};