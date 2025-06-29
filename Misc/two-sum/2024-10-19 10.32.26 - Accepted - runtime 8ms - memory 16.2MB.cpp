class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mp;
        vector<int> res;
        int n=nums.size();
        //stores the value in hashmap
        for(int i=0;i<n;i++){
            mp[nums[i]]=i;
        }
      
      //find the indexes
      for(int i=0;i<n;i++){
      int x;
      x=target-nums[i];
      if(mp.find(x)!=mp.end()){
        if(mp[x]!=i){
        res.push_back(i);
        res.push_back(mp[x]);

        break;
        }
      }


      }

return res;

    }
};