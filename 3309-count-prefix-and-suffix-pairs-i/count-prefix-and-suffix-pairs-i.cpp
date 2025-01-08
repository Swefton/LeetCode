class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int wordsLength = words.size();
        int result = 0;

        for (int i = 0; i < wordsLength - 1; ++i)
        {
            for (int j = i+1; j < wordsLength; ++j)
            {
                auto fix = words[i];
                auto word = words[j];

                if (word.substr(0, fix.size()) == fix && word.substr(word.size()-fix.size(), fix.size()) == fix) result++;

            }
        }    

        return result;    
    }
};