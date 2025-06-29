class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int size=floor(n/3);
vector<int> ans;
sort(nums.begin(),nums.end());
int count=1;
int i=0;
for(i=0;i<n-1;i++){
if(nums[i]==nums[i+1]){
    count++;
}
else{
    if(count>size){
        ans.push_back(nums[i]);

    }
    count=1;
}

}
if(count>size){
    ans.push_back(nums[i]);
}
return ans;
    }
};