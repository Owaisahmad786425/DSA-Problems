class Solution {
    // Recursive helper function to find the length of the Fibonacci-like subsequence
    int fun(int a, int b, unordered_map<int, int>& mp, vector<int>& arr, int n) {
        int sum = arr[a] + arr[b];
        
        // Check if the sum exists in the map
        if (mp.find(sum) != mp.end()) {
            int temp = mp[sum];
            // Recursively find the next element in the Fibonacci-like subsequence
            return 1 + fun(b, temp, mp, arr, n);  // Recur with the new pair (b, mp[sum])
        }
        
        // If no next element, return the current length of the subsequence (which is 2 initially)
        return 2;
    }

public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mp;

        // Create a map for quick lookup of each element's index
        for (int i = 0; i < n; i++) {
            mp[arr[i]] = i;
        }

        int maxi = 0;

        // Iterate over all pairs (i, j)
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // Start the Fibonacci-like subsequence with (arr[i], arr[j])
                int len = fun(i, j, mp, arr, n);
                if (len >= 3) {
                    maxi = max(maxi, len);  // Update the maximum length of subsequences
                }
            }
        }

        return maxi;  // Return the longest Fibonacci-like subsequence length
    }
};
