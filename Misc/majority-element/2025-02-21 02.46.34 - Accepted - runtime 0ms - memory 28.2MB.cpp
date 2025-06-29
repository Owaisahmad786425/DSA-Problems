class Solution {
public:

//mores voting algorithm
    int majorityElement(vector<int>& nums) {
         int element;
         int count=0;
         int n=nums.size();
for(int i=0;i<nums.size();i++){
    if(count==0){
        element=nums[i];
    }
    if(element==nums[i]){
        count++;
    }
    else if(element!=nums[i]){
        count--;
    }
}

return element;

    }
};