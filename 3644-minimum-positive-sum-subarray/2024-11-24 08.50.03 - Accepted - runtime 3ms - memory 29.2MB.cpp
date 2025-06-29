class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
    int mini = INT_MAX;

    // Step 1: Compute the prefix sum array
    std::vector<int> prefix(n + 1, 0);  // prefix[i] is the sum of nums[0...i-1]
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + nums[i];
    }

    // Step 2: Iterate through all subarray lengths from l to r
    for (int length = l; length <= r; length++) {
        // Step 3: Iterate over all starting positions for subarrays of this length
        for (int start = 0; start + length <= n; start++) {
            int end = start + length - 1;
            int subarraySum = prefix[end + 1] - prefix[start]; // sum of subarray nums[start...end]

            // Step 4: Check if the sum is positive and update the minimum sum
            if (subarraySum > 0) {
                mini = std::min(mini, subarraySum);
            }
        }
    }

    // Step 5: Return the result
    return (mini == INT_MAX) ? -1 : mini;
    }
};