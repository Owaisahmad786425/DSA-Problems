class Solution {
public:
    int mySqrt(int x) {
 if (x == 0) return 0;
    if (x == 1) return 1;

    int left = 0;
    int right = x;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        long long midSquared = (long long)mid * mid; // Use long long to prevent overflow

        if (midSquared == x) {
            return mid;
        } else if (midSquared < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return right;
    }
};