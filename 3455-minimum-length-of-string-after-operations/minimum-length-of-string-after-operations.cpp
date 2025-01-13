class Solution {
public:
    int minimumLength(string s) {
        int sum = 0;
        unordered_map<char, int> char_counter;

        for (auto i : s)
        {
            char_counter[i]++;
        }

        for (auto& it : char_counter)
        {
            if (it.second % 2 == 0)
            {
                sum += 2;
            }
            else
            {
                sum += 1;
            }
        }

        return sum;
    }
};