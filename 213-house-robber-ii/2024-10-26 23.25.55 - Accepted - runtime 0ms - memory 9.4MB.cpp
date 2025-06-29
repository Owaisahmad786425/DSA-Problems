class Solution {
private:
int f(vector<int> &temp){

int prev=temp[0];
int prev2=0;
int n=temp.size();
for(int i=1;i<n;i++){
    int take=temp[i];
    if(i>1){
        take=take+prev2;
    }
    int notake=0+prev;
int curr=max(take,notake);
  prev2=prev;
  prev=curr;
    }
    return prev;

}
public:
    int rob(vector<int>& nums) {
vector<int> temp1;
vector<int> temp2;

int n=nums.size();
if(n==0){
    return 0;
}
if(n==1){
    return nums[0];
}
for(int i=0;i<nums.size();i++){
    if(i!=0){
        temp1.push_back(nums[i]);
    }
    if(i!=n-1){
        temp2.push_back(nums[i]);
    }

}
int ans1=f(temp1);
int ans2=f(temp2);
return max(ans1,ans2);
    }
};