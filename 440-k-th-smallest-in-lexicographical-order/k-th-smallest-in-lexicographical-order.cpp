class Solution {
public:
    int findKthNumber(int n, int k) {
        auto countPrefix = [&](long prefix, long n) -> long {
            long count = 0;
            long current = prefix;
            long next = prefix + 1;
            
            while (current <= n) {
                count += min(n + 1, next) - current;
                current *= 10;
                next *= 10;
            }
            return count;
        };
        
        int current = 1;
        k--;
        
        while (k > 0) {
            long count = countPrefix(current, n);
            if (count <= k) {
                k -= count;
                current++;
            } else {
                k--;
                current *= 10;
            }
        }
        
        return current;
    }
};
