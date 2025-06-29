class Solution {
    int fun(int index, int XOR, vector<int> &nums,int n){
    if(index>=n){
        return 0;
    }
XOR^=nums[index];
int take=XOR+fun(index+1,XOR,nums,n);
XOR^=nums[index];
int not_take=fun(index+1,XOR,nums,n);
return (take+not_take);

    }
public:
    int subsetXORSum(vector<int>& nums) {
       int n=nums.size();
    int XOR=0;
    return fun(0,XOR,nums,n);

    }
};