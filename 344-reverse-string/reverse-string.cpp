class Solution {
public:
    void reverseString(vector<char>& s) {
        auto start = s.begin();
        auto end = s.end() - 1;

        while (start <= end) iter_swap(start++, end--);

    }
};