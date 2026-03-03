class Solution {
public:
    char findKthBit(int n, int k) {
        string s = "0";

        for (int i = 1; i < n; ++i) {
            string prev = s;

            string modified = prev;
            for (char& c : modified) {
                c = (c == '0') ? '1' : '0';
            }
            reverse(modified.begin(), modified.end());

            s = prev + "1" + modified;

            if (s.length() >= k)
                break;
        }

        return s[k - 1];
    }
};