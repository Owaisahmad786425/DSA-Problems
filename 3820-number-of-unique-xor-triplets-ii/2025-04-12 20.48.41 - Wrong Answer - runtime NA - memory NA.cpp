class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
       int count=n;
        if(n<3){
            return count;
        }
        set<int> st;
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        for(int i=0;i<n-2;i++){
            int j=i+1;
            int k=j+1;
            while(k<n){
            int temp=nums[i]^nums[j]^nums[k];
                if(st.find(temp)==st.end()){
                    st.insert(temp);
                    count++;
                }
                i++;
                k++;
            }
        }
        return count;
        
    }
};