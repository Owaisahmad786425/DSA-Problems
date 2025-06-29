class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> mp;
        int n= answers.size();
        for(int i=0;i<n;i++){
            mp[answers[i]]++;
        }
        int res=0;
        for(auto it:mp){
            int size=it.first+1;
            int count=it.second;
          int no_of_groups = (count + size - 1)/size;
            res+=(size*no_of_groups);
        }
        return res;
    }
};