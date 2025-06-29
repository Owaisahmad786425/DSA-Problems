class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
       vector<vector<int>> vec;
       set<vector<int>> st;
       sort(nums.begin(),nums.end());
       int n=nums.size();
    for(int i=0;i<=n-4;i++){
      
    int j=i+1;
    while(j<=n-3){

int k=j+1;
int l=n-1;
while(k<l){
long long  sum=(long long)nums[i]+nums[j]+nums[k]+nums[l];
if(sum<target){
    k++;
}
else if(sum==target){
 vector<int> temp;
 temp.push_back(nums[i]);
 temp.push_back(nums[j]);
 temp.push_back(nums[k]);
 temp.push_back(nums[l]);
st.insert(temp);
 k++;
 
}
else{
l--;



}


}
j++;
    }

    }
for(auto it:st){
    vec.push_back(it);
}
return vec;
    }
};