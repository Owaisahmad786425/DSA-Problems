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
int cnt=0;
for(int i=0;i<n;i++){
if(nums[i]==element){
    cnt++;
}
}
if(cnt>(n/2)){
return element;
}
return -1;
    }
};