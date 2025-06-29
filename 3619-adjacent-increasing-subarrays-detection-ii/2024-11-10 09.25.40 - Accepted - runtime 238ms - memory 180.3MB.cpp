class Solution {
bool canFormTwoAdjacentSubarrays(int k, const vector<int>& length) {
    int n = length.size();
    for (int i = 0; i <= n - 2 * k; ++i) {
        if (length[i] >= k && length[i + k] >= k) {
            return true;
        }
    }
    return false;
}
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
      int n = nums.size();
    
    // Step 1: Create the length array
    vector<int> length(n, 1);
    
    // Step 2: Populate the length array
    for (int i = n - 2; i >= 0; --i) {
        if (nums[i] < nums[i + 1]) {
            length[i] = length[i + 1] + 1;
        }
    }
    
    // Step 3: Perform binary search for maximum k
    int left = 1, right = n / 2, result = 0;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (canFormTwoAdjacentSubarrays(mid, length)) {
            result = mid;  // Update result and search for larger k
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return result;
    }
};