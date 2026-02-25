class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> count;
        for (auto i : arr) {
            count[i]++;
        }

        vector<int> pairs;
        for (auto pair : count) {
            pairs.push_back(pair.second);
        }

        sort(pairs.begin(), pairs.end(), [&](const auto a, const auto b){
            return a > b ? true : false;
        });

        int sum{0}, setCount{0};

        for (auto &pair : pairs) {
            sum+=pair;
            setCount++;
            if (sum >= arr.size()/2) {
                return setCount;
            }
        }

        return 0;
    }
};