class Solution {
public:
    int lengthOfLastWord(string s) {
        auto firstChar = find_if_not(s.rbegin(), s.rend(), [](char l){ return l == ' '; });
        auto wordEnd = find_if(firstChar, s.rend(), [](char l){ return l == ' '; });

        return wordEnd - firstChar;
    }
};