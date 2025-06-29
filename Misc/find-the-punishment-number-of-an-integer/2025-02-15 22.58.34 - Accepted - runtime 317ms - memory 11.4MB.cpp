class Solution {
    bool fun(string s, int i) {
        int n = s.size();
        // Try all possible ways to partition the square string s
        for (int mask = 1; mask < (1 << (n - 1)); ++mask) {
            int sum = 0;
            int start = 0;
            // Try splitting the string based on the mask
            for (int j = 0; j < n; ++j) {
                if (mask & (1 << j)) {  // If bit is set, we split here
                    string part = s.substr(start, j - start + 1);
                    sum += stoi(part);
                    start = j + 1;
                }
            }
            string last_part = s.substr(start, n - start);
            sum += stoi(last_part); // Add the last part

            if (sum == i) {
                return true;
            }
        }
        return false;
    }

public:
    int punishmentNumber(int n) {
        int sum = 0;
        for (int i = 1; i <= n; ++i) {
            int temp = i * i;
            string s = to_string(temp);

            // If the square has only one digit, no partition is needed
            if (s.size() == 1 && i == temp) {
                sum += temp;
            } 
            else {
                if (fun(s, i)) {
                    sum += temp;
                }
            }
        }
        return sum;
    }
};
