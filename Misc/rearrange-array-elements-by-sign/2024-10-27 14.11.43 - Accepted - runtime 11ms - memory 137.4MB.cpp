class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos;
        vector<int> neg;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
              pos.push_back(nums[i]);
            }
             if(nums[i]<0){
              neg.push_back(nums[i]);
            }
        }
int i=0;
int j=0;
while(i<pos.size()){
    nums[j]=pos[i];
    nums[j+1]=neg[i];
    i++;
    j=j+2;
}
return nums;
    }
};