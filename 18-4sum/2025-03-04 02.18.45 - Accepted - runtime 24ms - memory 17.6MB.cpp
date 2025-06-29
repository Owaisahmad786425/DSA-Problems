class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
       vector<vector<int>> vec;
       sort(nums.begin(),nums.end());
       int n=nums.size();
    for(int i=0;i<n;i++){
        if(i>0 &&nums[i]==nums[i-1]){
            continue;
        }
    int j=i+1;
    while(j<n){
 if(j>i+1 && nums[j]==nums[j-1]){
    j++;
    continue;
 }
int k=j+1;
int l=n-1;
while(k<l){
long long sum=(long long)nums[i]+nums[j]+nums[k]+nums[l];
if(sum<target){
    k++;
   
}
else if(sum==target){
 vector<int> temp;
 temp.push_back(nums[i]);
 temp.push_back(nums[j]);
 temp.push_back(nums[k]);
 temp.push_back(nums[l]);
 vec.push_back(temp);
 k++;
 while(k<l &&nums[k]==nums[k-1]){
    k++;
 }
}
else{
l--;



}


}
j++;
    }

    }

return vec;
    }
};