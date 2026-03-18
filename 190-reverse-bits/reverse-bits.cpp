class Solution {
public:
    int reverseBits(uint32_t n) {
        int res = 0;
        for (int i = 0; i < sizeof(int) * 8; i++) {
            res <<= 1;
            res |= (n & 1);
            n >>= 1;
        }
        return res;
    }
};