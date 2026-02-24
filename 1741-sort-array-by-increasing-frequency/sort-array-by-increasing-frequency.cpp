class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int> numCounter;
    
        for (auto i : nums) {
            numCounter[i]++;
        }

        sort(nums.begin(), nums.end(), [&](int a, int b) {
            if (numCounter[a] != numCounter[b]) {
                return numCounter[a] < numCounter[b];
            }
            return a > b; 
        });

        return nums;
    }
};