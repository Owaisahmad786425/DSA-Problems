class Solution {
public:
    bool divideArray(vector<int>& nums) {
  unordered_set<int>  st;
  int n=nums.size();
  for(int i=0;i<n;i++){
    if(st.find(nums[i])!=st.end()){
        st.erase(nums[i]);
    }
    else{
        st.insert(nums[i]);
    }
  }
      return st.size()==0;
    }
};