class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int maxscore = 0;
        vector<int> lettercount(26,0);
        for (char letter : letters) lettercount[letter - 'a']++;


        int numwords = words.size();
        for (int bitmask = 0; bitmask < (1 << numwords); ++bitmask) {
            vector<int> subsetcount(26, 0);
            for (int i = 0; i < numwords; ++i) {
                if (bitmask & (1 << i)) {
                    for (char letter : words[i]) {
                        subsetcount[letter - 'a']++;
                    }
                }
            }

            if (canformsubset(subsetcount, lettercount)) {
                int currentscore = calculatescore(subsetcount, score);
                maxscore = max(maxscore, currentscore);
            }
        }

        return maxscore;
    }

private:
    bool canformsubset(const vector<int>& subsetcount, const vector<int>& availablecount) {
        for (int i = 0; i < 26; ++i) {
            if (subsetcount[i] > availablecount[i]) return false;
            }
        return true;
    }

    int calculatescore(const vector<int>& subsetcount, const vector<int>& score) {
        int totalScore = 0;
        for (int i = 0; i < 26; ++i) {
            totalScore += subsetcount[i] * score[i];
            }
        return totalScore;
    }
};