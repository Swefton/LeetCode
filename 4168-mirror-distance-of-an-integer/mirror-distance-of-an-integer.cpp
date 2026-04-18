class Solution {
public:
    int mirrorDistance(int n) {
        int reverse = 0, copy = n;

        while (copy) {
            reverse += copy % 10;
            copy /= 10;
            reverse *= copy ? 10 : 1;
        }

        return abs(n - reverse);
    }
};