class Solution {
    int fun(int temp){
        int t=temp;
        int res=0;
        while(t>0){
         res++;
         t/=10;
        }
  return res;
    }
public:
    int findNumbers(vector<int>& nums) {
       int n=nums.size();
       int cnt=0;
       for(int i=0;i<n;i++){
        int temp=nums[i];
        if(fun(temp)%2==0){
            cnt++;
        }
       } 
       return cnt;
    }
};