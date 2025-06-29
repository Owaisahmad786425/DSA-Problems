class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
           int count = 0;
        int n = words.size();
        int m = pref.size();
        
        // Iterate over each word in the vector
        for (int i = 0; i < n; ++i) {
            string word = words[i];
            int wordSize = word.size();
            
            // Check if the word starts with the given prefix
            if (wordSize >= m && word.substr(0, m) == pref) {
                count++;
            }
        }
        return count;
    }
};