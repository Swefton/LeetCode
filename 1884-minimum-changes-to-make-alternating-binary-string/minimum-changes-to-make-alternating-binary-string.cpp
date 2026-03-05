class Solution {
public:
    int minOperations(string s) {
        int oneStart = 0;
        int zeroStart = 0;

        for (int i = 0; i < s.size(); ++i) {
            if (i%2 == 0) {
                if (s[i] == '1') {
                    zeroStart++;
                } else {
                    oneStart++;
                }
            } else {
                if (s[i] == '1') {
                    oneStart++;
                } else {
                    zeroStart++;
                }
            }
        }

        return min(oneStart, zeroStart);
    }
};