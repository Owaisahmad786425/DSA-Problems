class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
         int n = nums.size();
        
        // Helper function to check if a subarray is strictly increasing
        auto is_strictly_increasing = [&](int i) {
            for (int j = 0; j < k - 1; ++j) {
                if (nums[i + j] >= nums[i + j + 1]) {
                    return false;
                }
            }
            return true;
        };
        
        // Iterate through all possible starting points for the first subarray
        for (int i = 0; i <= n - 2 * k; ++i) {
            if (is_strictly_increasing(i) && is_strictly_increasing(i + k)) {
                return true;
            }
        }
        
        return false;
    }
};