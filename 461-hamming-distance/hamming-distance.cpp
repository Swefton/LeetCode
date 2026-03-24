class Solution {
public:
    int hammingDistance(int x, int y) {
        int distBits = x ^ y;
        int hammingDist = 0;

        while (distBits) {
            hammingDist += distBits & 1;
            distBits >>= 1;
        }

        return hammingDist;
    }
};