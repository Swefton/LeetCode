class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<pair<int,int>> placement;

        for (int i = 0; i < score.size(); ++i) {
            placement.push_back(make_pair(score[i], i));
        }

        sort(placement.begin(), placement.end(), [](const pair<int,int>& a, const pair<int,int>& b) {return a.first > b.first;});

        vector<string> result(score.size());

        for (int i = 0; i < placement.size(); ++i) {
            if (i == 0)
                result[placement[i].second] = "Gold Medal";
            else if (i == 1)
                result[placement[i].second] = "Silver Medal";
            else if (i == 2)
                result[placement[i].second] = "Bronze Medal";
            else
                result[placement[i].second] = to_string(i + 1);
        }

        return result;
    }
};
