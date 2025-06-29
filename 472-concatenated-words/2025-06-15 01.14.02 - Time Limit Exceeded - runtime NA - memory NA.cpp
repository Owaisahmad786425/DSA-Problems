class Solution {
    bool check(string word,unordered_set<string> &st){
        int n=word.size();
        for(int i=0;i<n;i++){
            string prefix=word.substr(0,i+1);
            string suffix=word.substr(i+1);
            if((st.find(prefix)!=st.end() && st.find(suffix)!=st.end()) ||  (st.find(prefix)!=st.end() && check(suffix,st))){
                return true;
            }
        }
        return false;
    }
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> st(begin(words),end(words));
         
   vector<string> res;
        for(int i=0;i<words.size();i++){
            if(check(words[i],st)){
    res.push_back(words[i]);
            }
        }
        return res;
    }
};