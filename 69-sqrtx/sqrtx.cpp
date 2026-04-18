class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;

        auto range = std::views::iota(1LL, (long long)x + 1);
        auto it = std::ranges::partition_point(range, [x](long long m) { return m * m <= (long long)x; });

        return (int)(*std::ranges::prev(it));
    }
};