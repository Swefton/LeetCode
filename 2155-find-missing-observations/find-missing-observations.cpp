class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int givenSum = 0;
        for (int roll : rolls) givenSum += roll;

        int totalRolls = n + rolls.size();
        int missingSum = mean * totalRolls - givenSum;

        if (n * 6 < missingSum || missingSum < n) return {};

        int remainder = missingSum % n;
        int quotient = missingSum / n;

        vector<int> result(n, quotient);
        for (int i = 0; i < remainder; i++)
            result[i]++;

        return result;
    }
};