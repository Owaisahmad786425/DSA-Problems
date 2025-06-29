class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> res;
        int n=words.size();
        int choose=groups[0];
        res.push_back(words[0]);
        for(int i=1;i<n;i++){
            if(groups[i]!=choose){
                res.push_back(words[i]);
                choose=groups[i];
            }
        }
        return res;
    }
};