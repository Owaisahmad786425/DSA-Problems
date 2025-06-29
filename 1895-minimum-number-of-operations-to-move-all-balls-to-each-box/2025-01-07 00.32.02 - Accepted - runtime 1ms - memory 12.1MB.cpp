class Solution {
public:
    vector<int> minOperations(string boxes) {
     int n = boxes.size();
        vector<int> result(n, 0);
        
        // Left to right pass
        int left_count = 0, left_moves = 0;
        for (int i = 1; i < n; i++) {
            if (boxes[i - 1] == '1') {
                left_count++;
            }
            left_moves += left_count;
            result[i] += left_moves;
        }
        
        // Right to left pass
        int right_count = 0, right_moves = 0;
        for (int i = n - 2; i >= 0; i--) {
            if (boxes[i + 1] == '1') {
                right_count++;
            }
            right_moves += right_count;
            result[i] += right_moves;
        }
        
        return result;
    }
};