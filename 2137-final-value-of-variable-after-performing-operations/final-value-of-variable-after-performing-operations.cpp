class Solution {
public:
    Solution() {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }

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
