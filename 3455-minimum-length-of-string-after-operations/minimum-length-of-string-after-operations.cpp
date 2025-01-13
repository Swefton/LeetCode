class Solution {
public:
    int minimumLength(string s) {
        int sum = 0;
        vector<int> char_counter(26, 0);

        for (auto i : s)
        {
            char_counter[i - 'a']++;
        }

        for (auto count : char_counter)
        {
            if (count != 0)
            {
                if (count % 2 == 0)
                {
                    sum += 2;
                }
                else
                {
                    sum += 1;
                }
            }
        }

        return sum;
    }
};