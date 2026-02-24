class Solution {
public:
    string sortString(string s) {
        int counts[26] = {0};
        for (char c : s) counts[c - 'a']++;

        string result = "";
        int remaining = s.length();

        while (remaining > 0) {
            for (int i = 0; i < 26; ++i) {
                if (counts[i] > 0) {
                    result += (char)(i + 'a');
                    counts[i]--;
                    remaining--;
                }
            }
            for (int i = 25; i >= 0; --i) {
                if (counts[i] > 0) {
                    result += (char)(i + 'a');
                    counts[i]--;
                    remaining--;
                }
            }
        }
        return result;
    }
};