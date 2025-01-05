class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> delta(n + 1, 0);

        for (auto& shift : shifts)
        {
            int start = shift[0], end = shift[1], direction = shift[2];
            delta[start] += (direction == 1 ? 1 : -1);
            delta[end + 1] -= (direction == 1 ? 1 : -1);
        }

        int cumulativeShift = 0;
        for (int i = 0; i < n; ++i)
        {
            cumulativeShift += delta[i];
            int shiftAmount = (cumulativeShift % 26 + 26) % 26;
            s[i] = 'a' + (s[i] - 'a' + shiftAmount) % 26;
        }

        return s;
    }
};
