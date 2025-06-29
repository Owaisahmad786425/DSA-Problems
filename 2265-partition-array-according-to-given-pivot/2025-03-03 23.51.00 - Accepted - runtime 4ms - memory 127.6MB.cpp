class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
     int n=nums.size();
     int less=0;
     int equal=0;
     int more=0;
     for(int i=0;i<n;i++){
     if(nums[i]<pivot){
        less++;
     }
     else if(nums[i]==pivot){
        equal++;
     }
     else{
        more++;
     }
     } 
      vector<int> res(n,0);
int low=0;
int mid=low+less;
int high=mid+equal;
for(int i=0;i<n;i++){
    if(nums[i]<pivot){
        res[low]=nums[i];
        low++;
    }
    else if(nums[i]==pivot){
        res[mid]=nums[i];
        mid++;
    }
    else{
        res[high]=nums[i];
        high++;
    }
}


return res;
    }
};