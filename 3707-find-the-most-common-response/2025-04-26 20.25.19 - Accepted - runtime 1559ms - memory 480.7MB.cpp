class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
     
        int n=responses.size();
           vector<set<string>> vec(n);
        for(int i=0;i<n;i++){
            int m=responses[i].size();
            for(int j=0;j<m;j++){
                vec[i].insert(responses[i][j]);
            }
        }
        map<string,int> mp;
        for(int i=0;i<n;i++){
            for(auto &it: vec[i]){
                mp[it]++;
            }
        }
  int maxi=0;
        for(auto &it:mp){
            maxi=max(maxi,it.second);
        }
     string res;
        for(auto &it:mp){
            if(it.second==maxi){
                res=it.first;
                break;
            }
        }
        return res;
    }
};