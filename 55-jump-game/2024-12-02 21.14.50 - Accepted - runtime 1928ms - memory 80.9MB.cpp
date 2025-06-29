class Solution {
    private:
    bool fun(int index,vector<int> &nums,int base, unordered_map<int, bool> &mp){
          if(index==base){
            return true;
        }
        if(index>base || nums[index]==0){
            return false;
        }
        if(mp.find(index)!=mp.end()){
            return mp[index];
        }
      
       int maxJump = nums[index];
    for (int i = 1; i <= maxJump; i++) {
        if (fun(index + i, nums, base,mp)) {
            mp[index]=true;
            return true; 
        }
    }
    mp[index]=false;
    return false;
    }
public:
    bool canJump(vector<int>& nums) {
        unordered_map<int, bool> mp;
        int n=nums.size();
        return fun(0,nums,n-1,mp);

    }
};