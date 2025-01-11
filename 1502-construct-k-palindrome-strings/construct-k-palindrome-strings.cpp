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

/**
class Solution {
public:
    bool canConstruct(string s, int k) {
        if (s.length() < k) return false;

        sort(s.begin(), s.end());
        int oddCount = 0;

        for (int i = 0; i < s.length(); ) {
            char current = s[i];
            int count = 0;
            while (i < s.length() && s[i] == current) {
                count++;
                i++;
            }
            if (count % 2 != 0) oddCount++;
        }

        return oddCount <= k;
    }
};
*/
