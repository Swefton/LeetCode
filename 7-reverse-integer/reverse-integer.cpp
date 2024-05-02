class Solution {
public:
    int reverse(int x) {
        int reversed = 0;
        
        while (x != 0) {
            int digit = x % 10;
            
            if (reversed > std::numeric_limits<int>::max() / 10 || 
                (reversed == std::numeric_limits<int>::max() / 10 && digit > 7)) {
                return 0;
            }
            if (reversed < std::numeric_limits<int>::min() / 10 || 
                (reversed == std::numeric_limits<int>::min() / 10 && digit < -8)) {
                return 0;
            }
            
            reversed = reversed * 10 + digit;
            x /= 10;
        }
        
        return reversed;
    }
};

