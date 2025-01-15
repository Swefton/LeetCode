class Solution {
public:
    int minimizeXor(int num1, int num2) {        
        int count = 0;
        int result = 0;

        while (num2)
        {
            num2 &= (num2 - 1); 
            count++;
        }

        for (int i = 31; i >= 0; --i)
        {
            if (count > 0 && ((num1 >> i) & 1)) {
                result |= (1 << i);
                count--;
            }
        }

        for (int i = 0; i < 32 && count > 0; ++i)
        {
            if (!((result >> i) & 1)) {
                result |= (1 << i);
                count--;
            }
        }

        return result;
    }
};
