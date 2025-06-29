class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> mp;
        int n=answers.size();
        int res=0;
        for(int i=0;i<n;i++){
            int group_size=answers[i]+1;;
            if(mp.find(group_size)==mp.end()){
                res+=group_size;
                mp[group_size]++;
            }
        
        }
        return res;
    }
};