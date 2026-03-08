class Solution {
public:
    string backtrack(int n, string curr, set<string>& s) {
        if (curr.size() == n) {
            if (s.find(curr) == s.end()) {
                return curr;
            }
            return "";
        }
    
        string res = backtrack(n, curr + "0", s);
        if (res != "") return res;
    
        return backtrack(n, curr + "1", s);
    }

    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        set<string> s(nums.begin(), nums.end());
        
        return backtrack(n, "", s);
    }
};