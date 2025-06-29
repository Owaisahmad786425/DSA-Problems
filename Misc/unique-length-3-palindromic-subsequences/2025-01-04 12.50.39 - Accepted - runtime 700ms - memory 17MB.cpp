class Solution {
public:
    int countPalindromicSubsequence(string s) {
       int n = s.size();
    
    // Step 1: Precompute the frequency of each character from the left and right
    vector<int> leftCount(26, 0);  // Frequency of characters to the left of the current index
    vector<int> rightCount(26, 0); // Frequency of characters to the right of the current index

    // Initialize rightCount with the frequency of each character in the entire string
    for (char c : s) {
        rightCount[c - 'a']++;
    }

    int palindromeCount = 0;
    unordered_set<string> uniquePalindromes;  // To store unique palindromes
    
    // Step 2: Traverse the string and count palindromes centered at each character s[j]
    for (int j = 0; j < n; ++j) {
        char middle = s[j];
        rightCount[middle - 'a']--;  // The middle character is no longer in the "right" part

        // Step 3: Count palindromes "aba" by checking characters to the left and right of the middle character
        for (int i = 0; i < 26; ++i) {
            if (leftCount[i] > 0 && rightCount[i] > 0) {
                string palindrome = {char(i + 'a'), middle, char(i + 'a')};
                uniquePalindromes.insert(palindrome);  // Insert the palindrome into the set
            }
        }

        // Step 4: Update the leftCount array after processing the middle character
        leftCount[middle - 'a']++;
    }

    // Step 5: Return the size of the set containing unique palindromes
    return uniquePalindromes.size();
    }
};