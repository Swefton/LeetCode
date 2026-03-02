class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        vector<int> zeroCount;

        for (auto row : grid) {
            int sum{0};

            for (auto i = row.rbegin(); i < row.rend(); ++i) {
                if (*i == 0) {
                    sum++;
                }
                else {
                    break;
                }
            }
            zeroCount.push_back(sum);
        }

        int swaps = 0;
        int n = zeroCount.size();
        for (int i = 0; i < n; ++i) {
            int target = n - 1 - i;
            int foundIdx = -1;

            for (int j = i; j < n; ++j) {
                if (zeroCount[j] >= target) {
                    foundIdx = j;
                    break;
                }
            }

            if (foundIdx == -1) return -1;

            for (int k = foundIdx; k > i; --k) {
                swap(zeroCount[k], zeroCount[k - 1]);
                swaps++;
            }
        }
        return swaps;
    }
};