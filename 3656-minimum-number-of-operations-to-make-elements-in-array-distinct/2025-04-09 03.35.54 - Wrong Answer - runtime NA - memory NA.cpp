class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp;
        int res=0;
        int index=-1;
        for(int i=n-1;i>=0;i--){
          if(mp.find(nums[i])==mp.end()){
            mp[nums[i]]++;
          }
          else{
            index=i;
            break;
          }
        }
    if(index==-1){
        return 0;
    }
   int size=index+1;
   if(size%3==0){
    return (size/3);
   }
   res=size/3;
   res+=(size%3);
   return res;

    }
};