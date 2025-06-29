class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n=nums.size();
    int count=0;
    int count1=0;
    int i=0;
    while(i<n&&nums[i]<=0){
        if(nums[i]==0){
            count++;
        }
        else{
            count1++;
        }
        i++;
    }
    return max(count1,(n-(count1+count)));

    }
};