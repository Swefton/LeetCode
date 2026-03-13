class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long low = 1;
        long long high = 1e16; 
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (canReduce(mid, mountainHeight, workerTimes)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

private:
    bool canReduce(long long maxTime, int targetHeight, const vector<int>& workerTimes) {
        long long totalHeightReduced = 0;
        for (int w : workerTimes) {
            long long val = 2 * maxTime / w;
            long long x = (-1 + sqrt(1 + 4 * val)) / 2;
            
            totalHeightReduced += x;
            if (totalHeightReduced >= targetHeight) return true;
        }
        return totalHeightReduced >= targetHeight;
    }
};