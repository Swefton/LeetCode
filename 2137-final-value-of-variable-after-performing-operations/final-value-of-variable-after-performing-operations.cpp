class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations)
    {
        int finalValue = 0;

        for (auto& number : operations)
        {
            if (number[1] == '-')
            {
                finalValue--;
            }
            else
            {
                finalValue++;
            }
        }
        
        return finalValue;
    }
};