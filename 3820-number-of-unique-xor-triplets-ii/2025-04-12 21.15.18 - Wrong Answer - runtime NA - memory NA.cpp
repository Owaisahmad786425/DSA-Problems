class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
      int n=nums.size();
        vector<int> prefix(n-1);
        for(int i=0;i<n-1;i++){
            prefix[i]=(nums[i]^nums[i+1]);
        }
        int count=n;
        unordered_set<int> st;
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        for(int i=0;i<n;i++){
            for(int j=i;j<n-1;j++){
                int temp=nums[i]^prefix[j];
                if(st.find(temp)==st.end()){
                    count++;
                    st.insert(temp);
                }
            }
        }
        return count;
    }
};