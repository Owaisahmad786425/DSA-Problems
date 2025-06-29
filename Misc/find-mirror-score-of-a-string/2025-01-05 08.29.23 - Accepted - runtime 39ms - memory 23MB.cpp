class Solution {
public:
    long long calculateScore(string s) {
  unordered_map<char, stack<int>> last_seen;  // To store unmarked indices of characters
    long long total_score = 0;  // To accumulate the score

    // Iterate over the string from left to right
    for (int i = 0; i < s.length(); ++i) {
        // Calculate the mirror character of s[i]
        char mirror_char = 'a' + ('z' - s[i]);

        // If the mirror character has been seen before and is unmarked
        if (!last_seen[mirror_char].empty()) {
            int j = last_seen[mirror_char].top();  // Get the index of the previous unmarked mirror character
            total_score += (i - j);  // Add the score for this pair

            // Remove both the current character and its mirror from the map (mark them as used)
            last_seen[mirror_char].pop();  // Mark the mirror character as used
        } else {
            // Otherwise, store the current character with its index for future possible matches
            last_seen[s[i]].push(i);
        }
    }

    return total_score;
        
    }
};