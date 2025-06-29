class Solution {
public:
    int minimumOperations(vector<int>& nums) {
     unordered_map<int,int> mp;
     int n=nums.size();
     for(int i=0;i<n;i++){
        mp[nums[i]]++;
     }
     int i=0;
     int count=0;
     while(i<n){
    bool flag=0;
    for(auto it:mp){
        if(it.second>1){
            flag=1;
            break;
        }
    }
    if(flag==1){
        int j;
        if(i>=n-2){
            count++;
            return count;
        }
        for(j=i;j<i+3;j++){
            mp[nums[j]]--;
            if(mp[nums[j]]==0){
                mp.erase(nums[j]);
            }
        }
        i=i+3;
        count++;

    }
    else{
        break;
    }
     }
     return count;
    }
};