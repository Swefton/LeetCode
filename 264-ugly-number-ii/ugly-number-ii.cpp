class Solution {
public:
    int nthUglyNumber(int n) {
        std::vector<int> ugly(n);
        ugly[0] = 1;
        int i2 = 0, i3 = 0, i5 = 0;
        int next_2 = 2, next_3 = 3, next_5 = 5;
        int next_ugly;

        for (int i = 1; i < n; i++) {
            next_ugly = std::min({next_2, next_3, next_5});
            ugly[i] = next_ugly;

            if (next_ugly == next_2) {
                i2++;
                next_2 = ugly[i2] * 2;
            }
            if (next_ugly == next_3) {
                i3++;
                next_3 = ugly[i3] * 3;
            }
            if (next_ugly == next_5) {
                i5++;
                next_5 = ugly[i5] * 5;
            }
        }
        return ugly[n-1];
    }
};
