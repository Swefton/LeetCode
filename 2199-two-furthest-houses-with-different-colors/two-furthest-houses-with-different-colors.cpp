class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int maxDist = 0;

        for (int i = 1; i < colors.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (colors[j] != colors[i]) {
                    maxDist = max(maxDist, i-j);
                    break;
                }
            }
        }

        return maxDist;
    }
};