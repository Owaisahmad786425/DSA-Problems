class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k =1;
        for(int i=1; i<nums.size();i++){
            if(nums[i] != nums[i-1]){
                k++;
            }
        }
        if (nums.size()==1){
            return k;
        }
        int start = 0;
        int j=start+1;
        while(start<k && j<nums.size()){
            if(nums[start] != nums[j]){
                nums[start+1] = nums[j];
                start++;
            }
            j++;
        }
        return k;
    }
};