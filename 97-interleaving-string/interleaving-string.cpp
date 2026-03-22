class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        size_t m = s1.size();
        size_t n = s2.size();


        if (s1.size() + s2.size() != s3.size()) return false;

        vector<vector<bool>> possMat(s1.size() + 1, vector<bool>(s2.size() + 1, false));

        // base case
        possMat[0][0] = true;

        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
               int s3Idx = i + j - 1;

               if (i > 0 && s1[i-1] == s3[s3Idx]) {
                if (possMat[i-1][j]) possMat[i][j] = true;
               }

               if (j > 0 && s2[j-1] == s3[s3Idx]) {
                if (possMat[i][j-1]) possMat[i][j] = true;
               }

            }
        }

        return possMat.back().back();
    }
};