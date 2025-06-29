class Solution {
    bool check(string word,unordered_map<string,int> &mp){
        int n=word.size();
        for(int i=0;i<n;i++){
            string prefix=word.substr(0,i+1);
            string suffix=word.substr(i+1);
            if((mp.find(prefix)!=mp.end() && mp.find(suffix)!=mp.end()) ||  (mp.find(prefix)!=mp.end() && check(suffix,mp))){
                return true;
            }
        }
        return false;
    }
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_map<string,int> mp;
        for(int i=0;i<words.size();i++){
             mp[words[i]]++;
        }
   vector<string> res;
        for(int i=0;i<words.size();i++){
            if(check(words[i],mp)){
    res.push_back(words[i]);
            }
        }
        return res;
    }
};