class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n = s.length();
        vector<int> prefixMasks(n + 1, 0);
        
        // Build prefix XOR masks
        for (int i = 0; i < n; ++i) {
            prefixMasks[i + 1] = prefixMasks[i] ^ (1 << (s[i] - 'a'));
        }

        vector<bool> results;
        results.reserve(queries.size());

        for (const auto& q : queries) {
            int left = q[0], right = q[1], k = q[2];
            
            // XOR gives the parity of characters in the range
            int mask = prefixMasks[right + 1] ^ prefixMasks[left];
            
            // Count bits set to 1 (odd frequencies)
            int oddCount = __builtin_popcount(mask);
            
            // Each replacement fixes 2 odd frequencies
            results.push_back(oddCount / 2 <= k);
        }

        return results;
    }
};