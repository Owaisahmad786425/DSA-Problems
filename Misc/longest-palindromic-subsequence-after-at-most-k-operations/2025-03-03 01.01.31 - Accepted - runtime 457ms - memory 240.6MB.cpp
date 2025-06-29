#include <vector>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
private:
    // Helper function to minimize the difference between characters
    int minDiff(char a, char b) {
        return min(abs(a - b), 26 - abs(a - b));
    }

    int fun(int index1, int index2, int k, string &s, vector<vector<vector<int>>> &dp) {
        // Base cases
        if (index1 == index2) {
            return 1;  // Single character is trivially a palindrome of length 1
        }
        if (index1 > index2) {
            return 0;  // Invalid substring (out of bounds)
        }
        if (k < 0) {
            return 0;  // No more moves allowed
        }
        
        // Check if the result is already computed
        if (dp[index1][index2][k] != -1) {
            return dp[index1][index2][k];
        }

        // Option 1: Do not take the current pair
        int not_take = max(fun(index1 + 1, index2, k, s, dp), fun(index1, index2 - 1, k, s, dp));

        // Option 2: Take the current pair (check if they can be made equal)
        int take = INT_MIN;
        int op = minDiff(s[index1], s[index2]);
        if (k >= op) {
            take = 2 + fun(index1 + 1, index2 - 1, k - op, s, dp);
        }

        // Memoize the result
        dp[index1][index2][k] = max(take, not_take);
        return dp[index1][index2][k];
    }

public:
    int longestPalindromicSubsequence(string s, int k) {
        int n = s.size();
        
        // Initialize the dp table with -1 indicating uncomputed states
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(k + 1, -1)));
        
        // Start the recursive function with the full range and k moves allowed
        return fun(0, n - 1, k, s, dp);
    }
};
