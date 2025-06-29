class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
      //binary search
      int low=0;
      int high=nums.size()-1;
      int mid;
      while(low<=high){
    mid=(low+high)/2;
if(target>nums[mid]){
    low=mid+1;
}
else if(target<nums[mid]){
    high=mid-1;
}
else{
    return mid;
}
      }
    if(high<low){
        return high+1;
    }
 return mid+1;
    }
};