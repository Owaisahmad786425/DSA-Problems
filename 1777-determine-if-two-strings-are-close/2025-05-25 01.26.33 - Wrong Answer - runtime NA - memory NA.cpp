class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size()){
            return false;
        }
        unordered_map<char,int> mp1,mp2;
        for(int i=0;i<word1.size();i++){
            mp1[word1[i]]++;
            mp2[word2[i]]++;
        }
int n=word1.size();
        //suppose we are changing word1 to word2
        for(int i=0;i<n;i++){
            if(mp2.find(word1[i])==mp1.end()){
                return false;
            }
        }
        return true;
    }
};