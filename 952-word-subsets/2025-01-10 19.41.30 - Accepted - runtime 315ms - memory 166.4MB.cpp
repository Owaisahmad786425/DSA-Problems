class Solution {
public:
unordered_map<char, int> getCharCount(const string& str) {
    unordered_map<char, int> count;
    for (char c : str) {
        count[c]++;
    }
    return count;
}
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
         unordered_map<char, int> maxRequiredCount;
    
    // Update maxRequiredCount with the maximum frequency needed for each character
    for (const string& b : words2) {
        unordered_map<char, int> currentCount = getCharCount(b);
        for (const auto& entry : currentCount) {
            maxRequiredCount[entry.first] = max(maxRequiredCount[entry.first], entry.second);
        }
    }
    
    // Step 2: Check each word in words1 if it satisfies the universal condition
    vector<string> result;
    
    for (const string& a : words1) {
        unordered_map<char, int> wordCount = getCharCount(a);
        bool isValid = true;
        
        // Check if word a contains at least the required number of each character from maxRequiredCount
        for (const auto& entry : maxRequiredCount) {
            if (wordCount[entry.first] < entry.second) {
                isValid = false;
                break; // Early exit if we fail to meet the requirement
            }
        }
        
        if (isValid) {
            result.push_back(a);
        }
    }
    
    return result;
    }
};