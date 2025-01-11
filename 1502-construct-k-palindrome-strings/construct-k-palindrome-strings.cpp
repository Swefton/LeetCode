class Solution {
public:
    bool canConstruct(string s, int k) {
        
        int pairs = 0;
        int odds = 0;

        unordered_map<char, int> char_count;

        for (auto letter : s)
        {
            char_count[letter]++;
        }

        for (auto& i: char_count)
        {
            pairs += i.second / 2;
            odds += i.second % 2;
        }        

        if (k >= odds && k <= s.size()) return true;
        else return false;
    }
};