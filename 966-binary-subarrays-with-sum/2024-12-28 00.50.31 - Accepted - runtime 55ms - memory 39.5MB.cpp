class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n =nums.size();
        int count=0;
    map<int,int> mp;
    mp[0]++;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=nums[i];
        int x=sum-goal;
        if(mp.find(x)!=mp.end()){
            count+=mp[x];
        }
        mp[sum]++;
    }
    return count;


    }
};