class Solution {
public:
    bool canBeValid(string s, string locked) {
        if (s.size() % 2 != 0) return false;

        int open = 0, flexible = 0;

        // Forward pass: Check if we can balance opening parentheses
        for (int i = 0; i < s.size(); ++i)
        {
            if (locked[i] == '1')
            {
                open += (s[i] == '(') ? 1 : -1;
            }
            else
            {
                flexible++;
            }

            if (open + flexible < 0) return false;
        }

        open = 0;
        flexible = 0;

        // Backward pass: Check if we can balance closing parentheses
        for (int i = s.size() - 1; i >= 0; --i)
        {
            if (locked[i] == '1')
            {
                open += (s[i] == ')') ? 1 : -1;
            }
            else
            {
                flexible++;
            }

            if (open + flexible < 0) return false;
        }

        return true;
    }
};
