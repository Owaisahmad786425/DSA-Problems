class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] != val){
                k++;
            }
        }

        int start=0;
        int j = 0;
        while(start<k){
            if(nums[j] !=val){
                swap(nums[start], nums[j]);
                start++;
            }
            j++;
        }
        return k;
    }
};