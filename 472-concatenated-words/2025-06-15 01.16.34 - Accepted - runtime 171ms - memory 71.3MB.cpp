class Solution {
    bool check(string &word, unordered_set<string> &st, unordered_map<string, bool> &memo) {
        if (memo.find(word) != memo.end()) return memo[word];

        int n = word.size();
        for (int i = 1; i < n; i++) {
            string prefix = word.substr(0, i);
            string suffix = word.substr(i);
            
            if (st.find(prefix) != st.end()) {
                if (st.find(suffix) != st.end() || check(suffix, st, memo)) {
                    return memo[word] = true;
                }
            }
        }
        return memo[word] = false;
    }

public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> st(begin(words), end(words));
        vector<string> res;
        unordered_map<string, bool> memo;

        for (auto &word : words) {
            if (word.empty()) continue;
            
            st.erase(word);  // Temporarily remove the word to avoid matching itself
            if (check(word, st, memo)) {
                res.push_back(word);
            }
            st.insert(word); 
        }

        return res;
    }
};
