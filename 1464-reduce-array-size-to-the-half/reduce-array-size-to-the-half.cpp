class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> count;
        for (auto i : arr) {
            count[i]++;
        }

        vector<pair<int,int>> pairs;
        for (auto pair : count) {
            pairs.push_back(pair);
        }

        sort(pairs.begin(), pairs.end(), [&](const auto a, const auto b){
            return a.second > b.second ? true : false;
        });

        int sum{0}, setCount{0};
        for (auto &pair : pairs) {
            sum+=pair.second;
            setCount++;
            if (sum >= arr.size()/2) {
                return setCount;
            }
        }

        return 0;
    }
};